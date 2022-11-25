#include <cstdlib>
#include <ctime>
#include <iostream>

#include "SOM.h"

glm::fvec3 **lattice;
glm::fvec3 *dataset;

int go = 0;
bool stop = true;
bool is_som_finished = false;
int map_width;
int map_height;
int datasteNum = 0;
const int max_iter = 20000;
int iter = 0;
double learning_rate = 0.1;
double radius = 5;
double n_learning_rate = 0.1;
double neighbor = 5;


glm::fvec3 **createMap(int map_width, int map_height, int *max);
glm::fvec3 *createInputDataset(VoxData_b* bounderVoxelData, int bounderNum);
const glm::fvec3 getInput(glm::fvec3 *dataset, int datasteNum);
void destroy(glm::fvec3 **arr, int width, int height);
void destroyDataset(glm::fvec3 *arr, int datasteNum);
void updateNode(glm::fvec3** lattice, glm::fvec3 nowInput,glm::ivec2 bmuId, glm::ivec2 nodeId, double radius, double learning_rate);
double computerate(int iter, double fun);
double computeradius(int iter, double fun);
double computeScale(double sigma, double dist);
bool isInNeighborhood(double squaredDist, double radius);

void SOM_Create(VoxData_b* bounderVoxelData, int bounderNum, int *max)
{
    srand(time(NULL));
    map_width = 20;//sqrt(bounderNum)/2;
    map_height = 20;//sqrt(bounderNum)/2;
    cout << map_width << ", " << map_height<<endl;
    // 1. Create lattice
    lattice = createMap(map_width, map_height, max);
    // 2. Create input dataset
    dataset = createInputDataset(bounderVoxelData, bounderNum);

    datasteNum = bounderNum;
}

void SOM_IterateOnce()
{
    
    // 1. Get one input from the dataset
    // 2. Find BMU
    // 3. Update BMU and the neighbors
    n_learning_rate = computerate(iter, learning_rate);
    neighbor = computeradius(iter, radius);

    const glm::fvec3 nowInput = getInput(dataset, datasteNum);
    double minDist = -1.0;
    glm::ivec2 bmu;
    // compute winner point
    for (int i = 0; i < map_width; i++)
    {
        for (int j = 0; j < map_height; j++)
        {
            double tmp = 0.0;
            tmp = pow(lattice[i][j].x - nowInput.x, 2) + pow(lattice[i][j].y - nowInput.y, 2)+ pow(lattice[i][j].z - nowInput.z, 2);

            if (minDist < 0.0)
            {
                minDist = tmp;
                bmu.x = 0;
                bmu.y = 0;
            }
            else
            {
                if (minDist > tmp)
                {
                    minDist = tmp;
                    bmu.x = i;
                    bmu.y = j;
                }
            }
        }
    }
    // renew winner point and neighnorhood
    for (int i = 0; i < map_width; i++)
    {
        for (int j = 0; j < map_height; j++)
        {
            glm::ivec2 node = glm::ivec2(i, j);
            glm::ivec2 diff = node - bmu;
            double squaredDist = static_cast<double>(diff.x * diff.x + diff.y * diff.y);
            // std::cout << "Dist " <<squaredDist<<std::endl;
            // std::cout << i<<", " << j << std::endl;
            if (isInNeighborhood(squaredDist, neighbor))
            {
                double n_radius = computeScale(neighbor, squaredDist);
                updateNode(lattice, nowInput, bmu, node, n_radius, n_learning_rate);
                
            }
        }
    }
    iter++; 
    // cout << iter<<endl;
}

void SOM_Destroy()
{
    // 1. Destroy lattice
    destroy(lattice, map_width, map_height);
    // 2. Destroy input dataset
    destroyDataset(dataset, datasteNum);
}

glm::fvec3 *createInputDataset(VoxData_b* bounderVoxelData, int bounderNum)
{
    glm::fvec3 *dataset = (glm::fvec3 *)malloc(sizeof(glm::fvec3) * bounderNum);

   
    for (int i = 0; i < bounderNum; i++)
    {
        double i0 = bounderVoxelData[i].bounderVoxelLocate.x;
        double j0 = bounderVoxelData[i].bounderVoxelLocate.y;
        double k0 = bounderVoxelData[i].bounderVoxelLocate.z;
        dataset[i] = {i0, j0, k0};
        // std::cout << i0<<", "<<j0<<", " <<k0<<", "<<std::endl;
    }
    return dataset;
}
glm::fvec3 **createMap(int map_width, int map_height, int *max)
{

    
    glm::fvec3 **lattice = (glm::fvec3 **)malloc(sizeof(glm::fvec3 *) * map_width);
    for (int i = 0; i < map_width; i++)
    {
        lattice[i] = (glm::fvec3 *)malloc(sizeof(glm::fvec3) * map_height);
    }
    for (int i = 0; i < map_width; i++)
    {
        for (int j = 0; j < map_height; j++)
        {
            double i0 = rand() % max[0];
            double j0 = rand() % max[1];
            double k0 = rand() % max[2];
            // std::cout << i0 << ", " << j0<<std::endl;
            lattice[i][j] = {i0, j0, k0};
        }
    }
    return lattice;
}
void destroy(glm::fvec3 **arr, int width, int height)
{
    for (int i = 0; i < width; i++)
    {
        free(arr[i]);
    }
}
void destroyDataset(glm::fvec3 *arr, int datasteNum){
    free(arr);
}
double computeradius(int iter, double fun)
{
    double lamda = ((double)(max_iter)) / log(fun);
    double sigma = fun * exp(-1 * ((double)iter) / lamda);
    return sigma;
}
double computerate(int iter, double fun)
{
    double sigma = fun * exp(-1 * ((double)iter) / ((double)(max_iter)) );
    return sigma;
}

const glm::fvec3 getInput(glm::fvec3 *dataset, int datasteNum)
{
    int i = rand() % datasteNum;
    return dataset[i];
}

bool isInNeighborhood(double squaredDist, double radius)
{
    if (squaredDist <= (radius * radius))
    {
        // std::cout << "dist : " << squaredDist << " radius : " << radius*radius << std::endl;
        return true;
    }
    return false;
}

double computeScale(double sigma, double dist)
{
    double theta = exp((-1 * dist) / (2 * pow(sigma, 2)));
    
    return theta;
}

void updateNode(glm::fvec3** lattice, glm::fvec3 nowInput,glm::ivec2 bmuId, glm::ivec2 nodeId, double radius, double learning_rate){
    lattice[nodeId.x][nodeId.y].x = lattice[nodeId.x][nodeId.y].x + radius * learning_rate*(nowInput.x-lattice[nodeId.x][nodeId.y].x);
    lattice[nodeId.x][nodeId.y].y = lattice[nodeId.x][nodeId.y].y + radius * learning_rate*(nowInput.y-lattice[nodeId.x][nodeId.y].y);
    lattice[nodeId.x][nodeId.y].z = lattice[nodeId.x][nodeId.y].z + radius * learning_rate*(nowInput.z-lattice[nodeId.x][nodeId.y].z);
    
}