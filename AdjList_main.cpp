#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <AdjList.h>

int main(){
    bool debug_addr = true;
    bool debug_name = true;
    bool debug_key = true;
    bool directed  = false;
    //Declare a new adjacent list to represent Graph(V, E)
    AdjList a1(directed);

    //Generate the Graph(V, E)
    LinkedListNode* node_a = new LinkedListNode(INT_MAX, "a");
    LinkedListNode* node_b = new LinkedListNode(INT_MAX, "b");
    LinkedListNode* node_h = new LinkedListNode(INT_MAX, "h");
    LinkedListNode* node_i = new LinkedListNode(INT_MAX, "i");
    LinkedListNode* node_c = new LinkedListNode(INT_MAX, "c");
    LinkedListNode* node_g = new LinkedListNode(INT_MAX, "g");
    LinkedListNode* node_f = new LinkedListNode(INT_MAX, "f");
    LinkedListNode* node_d = new LinkedListNode(INT_MAX, "d");
    LinkedListNode* node_e = new LinkedListNode(INT_MAX, "e");

    std::vector<LinkedListNode*> all_node;
    all_node.push_back(node_a);
    all_node.push_back(node_b);
    all_node.push_back(node_h);
    all_node.push_back(node_i);
    all_node.push_back(node_c);
    all_node.push_back(node_g);
    all_node.push_back(node_f);
    all_node.push_back(node_d);
    all_node.push_back(node_e);
    
    std::cout<<"-----------------LinkedListNode-----------------"<<std::endl;
    std::cout<<"node_a = ("<<node_a->GetData()<<", "<<node_a<<")"<<std::endl;
    std::cout<<"node_b = ("<<node_b->GetData()<<", "<<node_b<<")"<<std::endl;
    std::cout<<"node_h = ("<<node_h->GetData()<<", "<<node_h<<")"<<std::endl;
    std::cout<<"node_i = ("<<node_i->GetData()<<", "<<node_i<<")"<<std::endl;
    std::cout<<"node_c = ("<<node_c->GetData()<<", "<<node_c<<")"<<std::endl;
    std::cout<<"node_g = ("<<node_g->GetData()<<", "<<node_g<<")"<<std::endl;
    std::cout<<"node_f = ("<<node_f->GetData()<<", "<<node_f<<")"<<std::endl;
    std::cout<<"node_d = ("<<node_d->GetData()<<", "<<node_d<<")"<<std::endl;
    std::cout<<"node_e = ("<<node_e->GetData()<<", "<<node_e<<")"<<std::endl;
    std::cout<<"----------------All node-----------------"<<std::endl;
    for(size_t i=0;i<all_node.size();++i){
        if(i == all_node.size()-1){
            std::cout<<all_node[i]->GetName()<<"]"<<std::endl;
        }else if(i == 0){
            std::cout<<"all_node = ["<<all_node[i]->GetName()<<", ";
        }else{
            std::cout<<all_node[i]->GetName()<<", ";
        }
    }
    
    //Generate the correspondence between Fibonacci Node & LinkedListNode
    std::unordered_map<std::string, LinkedListNode*> map_node_st2ll;

    map_node_st2ll["a"] = node_a;
    map_node_st2ll["b"] = node_b;
    map_node_st2ll["h"] = node_h;
    map_node_st2ll["i"] = node_i;
    map_node_st2ll["c"] = node_c;
    map_node_st2ll["g"] = node_g;
    map_node_st2ll["f"] = node_f;
    map_node_st2ll["d"] = node_d;
    map_node_st2ll["e"] = node_e;
    std::cout<<"-----------------Set Adjacent List of Graph(V, E)-----------------"<<std::endl;
    a1.SetAdjList(node_a, node_b, 4);
    a1.SetAdjList(node_a, node_h, 8);
    a1.SetAdjList(node_b, node_c, 8);
    a1.SetAdjList(node_b, node_h, 11);
    a1.SetAdjList(node_h, node_g, 1);
    a1.SetAdjList(node_h, node_i, 7);
    a1.SetAdjList(node_g, node_f, 2);
    a1.SetAdjList(node_g, node_i, 6);
    a1.SetAdjList(node_c, node_i, 2);
    a1.SetAdjList(node_c, node_d, 7);
    a1.SetAdjList(node_c, node_f, 4);
    a1.SetAdjList(node_f, node_d, 14);
    a1.SetAdjList(node_f, node_e, 10);
    a1.SetAdjList(node_d, node_e, 9);
    std::cout<<"-----------------AdjList::PrintAdjList, node_a-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_a, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_b-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_b, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_h-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_h, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_c-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_c, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_i-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_i, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_g-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_g, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_d-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_d, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_e-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_e, debug_addr, debug_name, debug_key);
    std::cout<<"-----------------AdjList::PrintAdjList, node_f-----------------"<<std::endl;
    a1.PrintAdjList(map_node_st2ll, node_f, debug_addr, debug_name, debug_key);

    return EXIT_SUCCESS;
}
