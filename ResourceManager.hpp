#pragma once

#include "Resource.hpp"

class ResourceManager
{
    
private:
    Resource* resource; 

public:
    ResourceManager()
        : resource(new Resource())
    {}
    ResourceManager(const ResourceManager& other)
        : resource(new Resource(*other.resource))
    {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other)
        {
            delete resource;
            resource = new Resource(*other.resource);
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept
        : resource(other.resource)
    {
        other.resource = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other)
        {
            delete resource;
            resource = other.resource;
            other.resource = nullptr;
        }
        return *this;
    }

    ~ResourceManager()
    {
        delete resource;
    }

    double get()
    {
        return resource->get();
    }
};