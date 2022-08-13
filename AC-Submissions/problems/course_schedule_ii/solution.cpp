class Solution {
public:

    //cleaner code, concept same as ours 
    //https://leetcode.com/problems/course-schedule-ii/discuss/1333151/C%2B%2B-Simple-and-Clean-DFS-Solution
    
    // to understand our code better add the currDependents part at the end for the cyclic dependency case.: 
    unordered_set<int> added;
    bool dfs(int currCourse, vector<int>& order, unordered_set<int>& visited,
            unordered_map<int, vector<int>>& prerequisites, 
             unordered_set<int>& currDependents)
    {
        //cyclic dependency
        if(currDependents.find(currCourse) != currDependents.end())
            return false;
        
        if(visited.find(currCourse) !=  visited.end())
            return true;
        
        visited.insert(currCourse);
        currDependents.insert(currCourse);
        
        for(auto& course : prerequisites[currCourse])
        {
            if(!dfs(course, order, visited, prerequisites, currDependents))
                return false;
            if(added.find(course) == added.end())
            {
                added.insert(course);
                order.push_back(course);
            }
        }
        currDependents.erase(currCourse);
        if(added.find(currCourse) == added.end())
        {
            added.insert(currCourse);
            order.push_back(currCourse);
        }
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        unordered_set<int> visited, currDependents;
        unordered_map<int, vector<int>> prerequisitesMap;
        for(auto& preq : prerequisites)
            prerequisitesMap[preq[0]].push_back(preq[1]);
        for(int i = 0; i < numCourses; ++i)
            if(!dfs(i , order, visited, prerequisitesMap, currDependents))
                return {};
        return order;
    }
};