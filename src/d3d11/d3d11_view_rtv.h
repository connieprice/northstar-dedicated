#pragma once

#include "d3d11_device_child.h"

namespace dxvk {
  
  class D3D11Device;

  class D3D11RenderTargetView : public D3D11DeviceChild<ID3D11RenderTargetView1> {
    
  public:
    
    D3D11RenderTargetView(
            D3D11Device*                      pDevice,
            ID3D11Resource*                   pResource,
      const D3D11_RENDER_TARGET_VIEW_DESC1*   pDesc);
    
    ~D3D11RenderTargetView();
    
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) final;
    
    void STDMETHODCALLTYPE GetResource(ID3D11Resource** ppResource) final;
    
    void STDMETHODCALLTYPE GetDesc(D3D11_RENDER_TARGET_VIEW_DESC* pDesc) final;

    void STDMETHODCALLTYPE GetDesc1(D3D11_RENDER_TARGET_VIEW_DESC1* pDesc) final;

    static HRESULT GetDescFromResource(
            ID3D11Resource*                   pResource,
            D3D11_RENDER_TARGET_VIEW_DESC1*   pDesc);
    
    static D3D11_RENDER_TARGET_VIEW_DESC1 PromoteDesc(
      const D3D11_RENDER_TARGET_VIEW_DESC*    pDesc,
            UINT                              Plane);
    
    static HRESULT NormalizeDesc(
            ID3D11Resource*                   pResource,
            D3D11_RENDER_TARGET_VIEW_DESC1*   pDesc);

  private:
    
    ID3D11Resource*                   m_resource;
    D3D11_RENDER_TARGET_VIEW_DESC1    m_desc;
    
  };
  
}
