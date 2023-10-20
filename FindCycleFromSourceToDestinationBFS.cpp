// This function is implemented using BFS algorithm to find shortest path from source to destination
std::vector<size_t> FindPathFromPointToPoint(
  const AdjancencyMap& adjacencyMap
  , const std::size_t fromPoint
  , const std::size_t toPoint)
{
  std::vector<std::size_t> result;
  result.push_back(toPoint);
  std::queue<std::size_t> pointsToBeVisited;
  pointsToBeVisited.push(fromPoint);

  std::set<std::size_t> pointsAlreadyVisited;
  pointsAlreadyVisited.insert(fromPoint);

  std::unordered_map<std::size_t, std::size_t> parentOfNeighbour;

  while (!pointsToBeVisited.empty())
  {
    auto currentPoint = pointsToBeVisited.front();
    pointsToBeVisited.pop();

    if (currentPoint == toPoint)
    {
      break;
    }

    auto& neighbourPoints = GetNeighborVertices(adjacencyMap, currentPoint);

    for (const auto& neighbour : neighbourPoints)
    {
      if (pointsAlreadyVisited.find(neighbour) == pointsAlreadyVisited.end())
      {
        pointsToBeVisited.push(neighbour);
        pointsAlreadyVisited.insert(neighbour);
        parentOfNeighbour[neighbour] = currentPoint;
      }
    }
  }

  if (parentOfNeighbour.find(toPoint) != parentOfNeighbour.end())
  {
    std::size_t target = toPoint;

    result.push_back(target);

    while (target != fromPoint)
    {
      target = parentOfNeighbour[target];
      result.push_back(target);
    }

    reverse(result.begin() + 1, result.end());

    return result;
  }

  return result;

}

void RemoveEdgeBetweenPoints(std::size_t point1, std::size_t point2, AdjancencyMap& adjacencyMap)
{
  adjacencyMap[point1].erase(std::remove(adjacencyMap[point1].begin(), adjacencyMap[point1].end(), point2),
                             adjacencyMap[point1].end());
  adjacencyMap[point2].erase(std::remove(adjacencyMap[point2].begin(), adjacencyMap[point2].end(), point1),
                             adjacencyMap[point2].end());
}

void EstablishEdgeBetweenPoints(std::size_t point1, std::size_t point2, AdjancencyMap& adjacencyMap)
{
  adjacencyMap[point1].push_back(point2);
  adjacencyMap[point2].push_back(point1);
}

std::vector<std::size_t> FindCycleFromPoint(const std::set<EdgeIndex>& edges,
    std::size_t firstVertex)
{
  auto& adjacencyMap = CreateAdjacencyMap(edges);
  const auto& neighbourPoints = GetNeighborVertices(adjacencyMap, firstVertex);
  std::vector<std::vector<std::size_t>> paths;

  if (neighbourPoints.size() > 1)
  {
    for (int neighbourPoint = 0; neighbourPoint < neighbourPoints.size(); neighbourPoint++)
    {
      const size_t element = neighbourPoints[neighbourPoint];
      // Remove edge between points
      RemoveEdgeBetweenPoints(firstVertex, element, adjacencyMap);
      // Find path using BFS algorithm
      const auto cycle = FindPathFromPointToPoint(adjacencyMap, element, firstVertex);
      paths.push_back(cycle);
      // Establish edge between points
      EstablishEdgeBetweenPoints(firstVertex, element, adjacencyMap);
    }
  }
  else
  {
    std::vector<std::size_t> cycle{ firstVertex };
    paths.push_back(cycle);
  }

  std::cout << "Number of cycles found is : " << paths.size() << std::endl;

  for (auto i : paths)
  {
    std::cout << "Cycle is : ";

    for (auto j : i)
    {
      std::cout << j << "->";
    }
    std::cout << std::endl;
  }

  // Find Shortest cycle from all the cycles
  const auto minimumPathIterator = std::min_element(paths.begin(), paths.end(), [](const auto & a, const auto & b)
  {
    return a.size() < b.size();
  });

  return *minimumPathIterator;

}
