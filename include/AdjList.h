#ifndef _ADJ_LIST_H_
#define _ADJ_LIST_H_
#include <cstdlib>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <Linked_List.h>

class AdjList : public LinkedListNode, public LinkedList{
    std::unordered_map<LinkedListNode*, LinkedList*> map_linked_list;
    std::unordered_map<LinkedListNode*, std::unordered_map<LinkedListNode*, int>> map_weight;//map_weight[from_edge][to_edge] = weight
    std::vector<LinkedList*> collect_linked_list;

    public : 
        AdjList() : LinkedListNode(), LinkedList(){};
        ~AdjList();

        void                SetAdjList(LinkedListNode* const head_node, LinkedListNode* const inserted_node, const int weight);
        void                PrintAdjList(std::unordered_map<std::string, LinkedListNode*> &map_node_st2ll, LinkedListNode* const head_node, const bool debug_addr = false, const bool debug_name = false, const bool debug_key = true);
        inline LinkedList*  ReadAdjList(LinkedListNode* const head_node) {return map_linked_list[head_node];};
        inline std::unordered_map<LinkedListNode*, std::unordered_map<LinkedListNode*, int>>& \
                            ReadMapWeight() {return map_weight;};
};

#endif
