void FindAllCycles(const AdjancencyMap& adjacencyMap, std::size_t fromVertex, std::size_t toVertex,
                   std::set<std::size_t>& pointsAlreadyVisited,
                   std::vector<std::size_t>& path, std::vector<std::vector<std::size_t>>& allCycles)
{
  pointsAlreadyVisited.insert(toVertex);
  const auto& neighbourPoints = GetNeighborVertices(adjacencyMap, toVertex);
  for (const auto& neighbour : neighbourPoints)
  {
    if (neighbour == fromVertex && path.size() > 2)
    {
      path.push_back(fromVertex);
      allCycles.push_back(path);
      path.pop_back();
    }
    else if (pointsAlreadyVisited.find(neighbour) == pointsAlreadyVisited.end())
    {
      path.push_back(neighbour);
      FindAllCycles(adjacencyMap, fromVertex, neighbour, pointsAlreadyVisited, path, allCycles);
      path.pop_back();
    }
  }
  if (pointsAlreadyVisited.find(toVertex) != pointsAlreadyVisited.end())
  {
    pointsAlreadyVisited.erase(pointsAlreadyVisited.find(toVertex));
  }
}

std::vector<std::size_t> FindCycleFromPoint(const std::set<EdgeIndex>& edges,
    std::size_t firstVertex)
{
  auto& adjacencyMap = CreateAdjacencyMap(edges);
  std::vector<std::vector<std::size_t>> allCycles;
  std::vector<std::size_t> path;
  std::set<std::size_t> pointsAlreadyVisited;

  for (auto& adj : adjacencyMap)
  {
    const auto vertex = adj.first;
    path.push_back(vertex);
    FindAllCycles(adjacencyMap, vertex, vertex, pointsAlreadyVisited, path, allCycles);
    path.pop_back();
    pointsAlreadyVisited.clear();
  }

  std::cout << "Number of cycles found is : " << allCycles.size() << std::endl;

  for (auto i : allCycles)
  {
    std::cout << "Cycle is : ";

    for (auto j : i)
    {
      std::cout << j << "->";
    }
    std::cout << std::endl;
  }

  if (allCycles.empty())
  {
    return {};
  }

  // Find longest cycle from all the cycles
  const auto maximumPathIterator = std::max_element(allCycles.begin(), allCycles.end(), [](const auto & a, const auto & b)
  {
    return a.size() < b.size();
  });

  return *maximumPathIterator;
}
