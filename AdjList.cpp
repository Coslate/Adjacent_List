#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <AdjList.h>

AdjList::~AdjList(){
    if(show_debug_msg){
        std::cout<<"It is AdjList destructor."<<std::endl;
    }
    for(size_t i=0;i<collect_linked_list.size();++i){
        LinkedList* the_linked_list = collect_linked_list[i];
        delete the_linked_list;
    }
}
void AdjList::SetAdjList(LinkedListNode* const head_node, LinkedListNode* const inserted_node, const int weight){
    if(map_linked_list.find(head_node) == map_linked_list.end()){
        LinkedList* the_linked_list = new LinkedList();
        the_linked_list->InsertTail(weight, inserted_node->GetName());
        map_linked_list[head_node] = the_linked_list;
        collect_linked_list.push_back(the_linked_list);
    }else{
        LinkedList* the_linked_list = map_linked_list[head_node];
        the_linked_list->InsertTail(weight, inserted_node->GetName());
    }
    map_weight[head_node][inserted_node] = weight;

    if(!directed){
        //The Adjacent List of an undirected graph is bi-directional, which is O(2E)
        if(map_linked_list.find(inserted_node) == map_linked_list.end()){
            LinkedList* the_linked_list = new LinkedList();
            the_linked_list->InsertTail(weight, head_node->GetName());
            map_linked_list[inserted_node] = the_linked_list;
            collect_linked_list.push_back(the_linked_list);
        }else{
            LinkedList* the_linked_list = map_linked_list[inserted_node];
            the_linked_list->InsertTail(weight, head_node->GetName());
        }
        map_weight[inserted_node][head_node] = weight;
    }
}
void AdjList::PrintAdjList(std::unordered_map<std::string, LinkedListNode*> &map_node_st2ll, LinkedListNode* const head_node, const bool debug_addr, const bool debug_name, const bool debug_key, const bool debug_explored){
    int count = 0;
    LinkedList* the_linked_list;

    std::cout<<">>>>> The node:"<<head_node->GetName()<<"("<<head_node<<") : "<<std::endl;
    if(map_linked_list.find(head_node) != map_linked_list.end()){
        the_linked_list = map_linked_list[head_node];
        the_linked_list->PrintList(debug_addr, debug_name, debug_key, debug_explored);
    }else{
        std::cout<<"Warning : The head_node has no Adjacent List."<<std::endl;
        return;
    }

    LinkedListNode* current_node = the_linked_list->GetFristNode();
    while(current_node != NULL){
        if((count == 0) && (count == (the_linked_list->GetListSize()-1))){
            std::cout<<"map_weight["<<head_node->GetName()<<"] = ["<<map_weight[map_node_st2ll[head_node->GetName()]][map_node_st2ll[current_node->GetName()]]<<"("<<map_node_st2ll[head_node->GetName()]<<", "<<map_node_st2ll[current_node->GetName()]<<")"<<"]"<<std::endl;
        }else if(count == 0){
            std::cout<<"map_weight["<<head_node->GetName()<<"] = ["<<map_weight[map_node_st2ll[head_node->GetName()]][map_node_st2ll[current_node->GetName()]]<<"("<<map_node_st2ll[head_node->GetName()]<<", "<<map_node_st2ll[current_node->GetName()]<<")"<<", ";
        }else if(count == the_linked_list->GetListSize()-1){
            std::cout<<map_weight[map_node_st2ll[head_node->GetName()]][map_node_st2ll[current_node->GetName()]]<<"("<<map_node_st2ll[head_node->GetName()]<<", "<<map_node_st2ll[current_node->GetName()]<<")"<<"]"<<std::endl;
        }else{
            std::cout<<map_weight[map_node_st2ll[head_node->GetName()]][map_node_st2ll[current_node->GetName()]]<<"("<<map_node_st2ll[head_node->GetName()]<<", "<<map_node_st2ll[current_node->GetName()]<<")"<<", ";
        }
        ++count;
        current_node = current_node->GetNext();
    }
}
