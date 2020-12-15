/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto
 *               (Shared logic for modifications)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CClientModelManager.h
 *  PURPOSE:     Model manager class
 *
 *****************************************************************************/

class CClientModelManager;

#pragma once

#include <list>
#include <vector>
#include <memory>
#include "CClientModel.h"

class CClientModelManager
{
    friend class CClientModel;

public:
    CClientModelManager::CClientModelManager();
    ~CClientModelManager(void);

    void RemoveAll(void);

    void Add(const std::shared_ptr<CClientModel>& pModel);
    bool Remove(const std::shared_ptr<CClientModel>& pModel);

    int GetFirstFreeModelID(void);

    std::shared_ptr<CClientModel> FindModelByID(int iModelID);
    bool RequestModel(int iModelID, ushort usParentID, eClientModelType eModelType, CClientManager* pManager, CResource* pResource = NULL);

    std::vector<std::shared_ptr<CClientModel>> GetModelsByType(eClientModelType type, const unsigned int minModelID = 0);

    void DeallocateModelsAllocatedByResource(CResource* pResource);

private:
    std::unique_ptr<std::shared_ptr<CClientModel>[]> m_Models;
    unsigned int m_modelCount = 0;
};
