#include <iostream>
#include <vector>
#include <string>
#include <sstream>

template <typename BlockType>
class Block{
    public:
        bool full = false;
        BlockType size;
        int id;

        Block(int id,BlockType size):id(id),size(size){}
};

template <typename ProcessType>
class Process{
    public:
        bool allocated = false;
        ProcessType size;
        int allocatedIn = -1;

        Process(ProcessType size):size(size){}
};

void BestFit(std::vector<Block<int>*> blocks,std::vector<Process<int>*> processes){
    for (int p = 0; p < processes.size(); p++){
        int minWasteBlock = -1;

        for (int b = 0; b < blocks.size(); b++){
            if (
                !blocks[b]->full && 
                blocks[b]->size >= processes[p]->size && 
                (
                    minWasteBlock < 0 || 
                    blocks[minWasteBlock]->size > blocks[b]->size
                )
            ){
                minWasteBlock = b;
            }
        }

        if (minWasteBlock >= 0){
            processes[p]->allocated = true;
            processes[p]->allocatedIn = blocks[minWasteBlock]->id;

            int blockSize = blocks[minWasteBlock]->size;
            int blockId = blocks[minWasteBlock]->id;

            delete blocks[minWasteBlock];

            blocks[minWasteBlock] = new Block<int>(blockId,processes[p]->size);
            blocks[minWasteBlock]->full = true;

            blocks.insert(
                blocks.begin() + minWasteBlock+1,
                new Block<int>(blockId,blockSize - processes[p]->size)
            );
        }
    }

    for (int p = 0; p < processes.size(); p++){
        std::cout << "Process " << p+1 << " (" << processes[p]->size << ") -> ";
        if (processes[p]->allocated){
            std::cout << "Block " << processes[p]->allocatedIn << std::endl;
        } else {
            std::cout << "Not Allocated" << std::endl;
        }
    }
}

void WorstFit(std::vector<Block<int>*> blocks,std::vector<Process<int>*> processes){
    for (int p = 0; p < processes.size(); p++){
        int maxWasteBlock = -1;

        for (int b = 0; b < blocks.size(); b++){
            if (
                !blocks[b]->full && 
                blocks[b]->size >= processes[p]->size && 
                (
                    maxWasteBlock < 0 || 
                    blocks[maxWasteBlock]->size < blocks[b]->size
                )
            ){
                maxWasteBlock = b;
            }
        }

        if (maxWasteBlock >= 0){
            processes[p]->allocated = true;
            processes[p]->allocatedIn = blocks[maxWasteBlock]->id;

            int blockSize = blocks[maxWasteBlock]->size;
            int blockId = blocks[maxWasteBlock]->id;

            delete blocks[maxWasteBlock];

            blocks[maxWasteBlock] = new Block<int>(blockId,processes[p]->size);
            blocks[maxWasteBlock]->full = true;

            blocks.insert(
                blocks.begin() + maxWasteBlock+1,
                new Block<int>(blockId,blockSize - processes[p]->size)
            );
        }
    }

    for (int p = 0; p < processes.size(); p++){
        std::cout << "Process " << p+1 << " (" << processes[p]->size << ") -> ";
        if (processes[p]->allocated){
            std::cout << "Block " << processes[p]->allocatedIn << std::endl;
        } else {
            std::cout << "Not Allocated" << std::endl;
        }
    }
}

int main(){
    std::string blocks_inp,processes_inp,word;
    std::vector<Block<int>*> blocks;
    std::vector<Process<int>*>processes;
    
    std::cout << "Enter memory blocks : ";
    std::getline(std::cin,blocks_inp);
    std::stringstream bss(blocks_inp);
    
    std::cout << "Enter process sizes : ";
    std::getline(std::cin,processes_inp);
    std::stringstream pss(processes_inp);   

    int count = 1;
    while (bss >> word)
        blocks.push_back(new Block<int>(count++,std::stoi(word)));
        
    while (pss >> word)
        processes.push_back(new Process<int>(std::stoi(word)));
    

    std::cout << "\nBest Fit Approach" << std::endl;
    BestFit(blocks,processes);

    blocks = std::vector<Block<int>*>();
    processes = std::vector<Process<int>*>();

    bss.clear();
    bss.seekg(0);
    pss.clear();
    pss.seekg(0);

    count = 1;
    while (bss >> word)
        blocks.push_back(new Block<int>(count++,std::stoi(word)));
    
    while (pss >> word)
        processes.push_back(new Process<int>(std::stoi(word)));

    std::cout << "\n\nWorst Fit Approach" << std::endl;
    WorstFit(blocks,processes);

    return 0;
}