// AS added for debugging purposes
#include <iostream>

#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    // ASE 5
    //_chatBot = nullptr; // Remove delete operation because it uses a shallow copy of the handle currently owned by ChatLogic
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}
// ASE
// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
// {
//    _childEdges.push_back(edge);
//}
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
   _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
//ASE 5
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
//void GraphNode::MoveChatbotHere(std::unique_ptr<ChatBot> chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);

    //_chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // ASE 5
    //newNode->MoveChatbotHere(_chatBot);
    //_chatBot = nullptr; // invalidate pointer at source
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
    // ASE 4
    //return _childEdges[index];
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}