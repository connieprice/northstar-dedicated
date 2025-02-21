#pragma once

#include "d3d11_annotation.h"
#include "d3d11_context_state.h"
#include "d3d11_device_child.h"
#include "d3d11_texture.h"

namespace dxvk {
  
  class D3D11Device;
  
  class D3D11DeviceContext : public D3D11DeviceChild<ID3D11DeviceContext4> {
  public:
    
    D3D11DeviceContext(D3D11Device* pParent);
    ~D3D11DeviceContext();
    
    HRESULT STDMETHODCALLTYPE QueryInterface(
            REFIID  riid,
            void**  ppvObject);
    
    void STDMETHODCALLTYPE DiscardResource(ID3D11Resource *pResource);

    void STDMETHODCALLTYPE DiscardView(ID3D11View* pResourceView);

    void STDMETHODCALLTYPE DiscardView1(
            ID3D11View*                      pResourceView,
      const D3D11_RECT*                      pRects,
            UINT                             NumRects);
    
    void STDMETHODCALLTYPE ClearState();
    
    void STDMETHODCALLTYPE SetPredication(
            ID3D11Predicate*                  pPredicate,
            BOOL                              PredicateValue);
    
    void STDMETHODCALLTYPE GetPredication(
            ID3D11Predicate**                 ppPredicate,
            BOOL*                             pPredicateValue);
    
    void STDMETHODCALLTYPE CopySubresourceRegion(
            ID3D11Resource*                   pDstResource,
            UINT                              DstSubresource,
            UINT                              DstX,
            UINT                              DstY,
            UINT                              DstZ,
            ID3D11Resource*                   pSrcResource,
            UINT                              SrcSubresource,
      const D3D11_BOX*                        pSrcBox);
    
    void STDMETHODCALLTYPE CopySubresourceRegion1(
            ID3D11Resource*                   pDstResource,
            UINT                              DstSubresource,
            UINT                              DstX,
            UINT                              DstY,
            UINT                              DstZ,
            ID3D11Resource*                   pSrcResource,
            UINT                              SrcSubresource,
      const D3D11_BOX*                        pSrcBox,
            UINT                              CopyFlags);
    
    void STDMETHODCALLTYPE CopyResource(
            ID3D11Resource*                   pDstResource,
            ID3D11Resource*                   pSrcResource);
    
    void STDMETHODCALLTYPE CopyStructureCount(
            ID3D11Buffer*                     pDstBuffer,
            UINT                              DstAlignedByteOffset,
            ID3D11UnorderedAccessView*        pSrcView);

    void STDMETHODCALLTYPE CopyTiles(
            ID3D11Resource*                   pTiledResource,
      const D3D11_TILED_RESOURCE_COORDINATE*  pTileRegionStartCoordinate,
      const D3D11_TILE_REGION_SIZE*           pTileRegionSize,
            ID3D11Buffer*                     pBuffer,
            UINT64                            BufferStartOffsetInBytes,
            UINT                              Flags);
    
    HRESULT STDMETHODCALLTYPE CopyTileMappings(
            ID3D11Resource*                   pDestTiledResource,
      const D3D11_TILED_RESOURCE_COORDINATE*  pDestRegionStartCoordinate,
            ID3D11Resource*                   pSourceTiledResource,
      const D3D11_TILED_RESOURCE_COORDINATE*  pSourceRegionStartCoordinate,
      const D3D11_TILE_REGION_SIZE*           pTileRegionSize,
            UINT                              Flags);

    HRESULT STDMETHODCALLTYPE ResizeTilePool(
            ID3D11Buffer*                     pTilePool,
            UINT64                            NewSizeInBytes);

    void STDMETHODCALLTYPE TiledResourceBarrier(
            ID3D11DeviceChild*                pTiledResourceOrViewAccessBeforeBarrier,
            ID3D11DeviceChild*                pTiledResourceOrViewAccessAfterBarrier);

    void STDMETHODCALLTYPE ClearRenderTargetView(
            ID3D11RenderTargetView*           pRenderTargetView,
      const FLOAT                             ColorRGBA[4]);
    
    void STDMETHODCALLTYPE ClearUnorderedAccessViewUint(
            ID3D11UnorderedAccessView*        pUnorderedAccessView,
      const UINT                              Values[4]);
    
    void STDMETHODCALLTYPE ClearUnorderedAccessViewFloat(
            ID3D11UnorderedAccessView*        pUnorderedAccessView,
      const FLOAT                             Values[4]);
    
    void STDMETHODCALLTYPE ClearDepthStencilView(
            ID3D11DepthStencilView*           pDepthStencilView,
            UINT                              ClearFlags,
            FLOAT                             Depth,
            UINT8                             Stencil);
    
    void STDMETHODCALLTYPE ClearView(
            ID3D11View                        *pView,
      const FLOAT                             Color[4],
      const D3D11_RECT                        *pRect,
            UINT                              NumRects);

    void STDMETHODCALLTYPE GenerateMips(
            ID3D11ShaderResourceView*         pShaderResourceView);
    
    void STDMETHODCALLTYPE UpdateSubresource(
            ID3D11Resource*                   pDstResource,
            UINT                              DstSubresource,
      const D3D11_BOX*                        pDstBox,
      const void*                             pSrcData,
            UINT                              SrcRowPitch,
            UINT                              SrcDepthPitch);
    
    void STDMETHODCALLTYPE UpdateSubresource1(
            ID3D11Resource*                   pDstResource,
            UINT                              DstSubresource,
      const D3D11_BOX*                        pDstBox,
      const void*                             pSrcData,
            UINT                              SrcRowPitch,
            UINT                              SrcDepthPitch,
            UINT                              CopyFlags);

    HRESULT STDMETHODCALLTYPE UpdateTileMappings(
            ID3D11Resource*                   pTiledResource,
            UINT                              NumTiledResourceRegions,
      const D3D11_TILED_RESOURCE_COORDINATE*  pTiledResourceRegionStartCoordinates,
      const D3D11_TILE_REGION_SIZE*           pTiledResourceRegionSizes,
            ID3D11Buffer*                     pTilePool,
            UINT                              NumRanges,
      const UINT*                             pRangeFlags,
      const UINT*                             pTilePoolStartOffsets,
      const UINT*                             pRangeTileCounts,
            UINT                              Flags);

    void STDMETHODCALLTYPE UpdateTiles(
            ID3D11Resource*                   pDestTiledResource,
      const D3D11_TILED_RESOURCE_COORDINATE*  pDestTileRegionStartCoordinate,
      const D3D11_TILE_REGION_SIZE*           pDestTileRegionSize,
      const void*                             pSourceTileData,
            UINT                              Flags);

    void STDMETHODCALLTYPE SetResourceMinLOD(
            ID3D11Resource*                   pResource,
            FLOAT                             MinLOD);
    
    FLOAT STDMETHODCALLTYPE GetResourceMinLOD(
            ID3D11Resource*                   pResource);
    
    void STDMETHODCALLTYPE ResolveSubresource(
            ID3D11Resource*                   pDstResource,
            UINT                              DstSubresource,
            ID3D11Resource*                   pSrcResource,
            UINT                              SrcSubresource,
            DXGI_FORMAT                       Format);
    
    void STDMETHODCALLTYPE DrawAuto();
    
    void STDMETHODCALLTYPE Draw(
            UINT            VertexCount,
            UINT            StartVertexLocation);
    
    void STDMETHODCALLTYPE DrawIndexed(
            UINT            IndexCount,
            UINT            StartIndexLocation,
            INT             BaseVertexLocation);
    
    void STDMETHODCALLTYPE DrawInstanced(
            UINT            VertexCountPerInstance,
            UINT            InstanceCount,
            UINT            StartVertexLocation,
            UINT            StartInstanceLocation);
    
    void STDMETHODCALLTYPE DrawIndexedInstanced(
            UINT            IndexCountPerInstance,
            UINT            InstanceCount,
            UINT            StartIndexLocation,
            INT             BaseVertexLocation,
            UINT            StartInstanceLocation);
    
    void STDMETHODCALLTYPE DrawIndexedInstancedIndirect(
            ID3D11Buffer*   pBufferForArgs,
            UINT            AlignedByteOffsetForArgs);
    
    void STDMETHODCALLTYPE DrawInstancedIndirect(
            ID3D11Buffer*   pBufferForArgs,
            UINT            AlignedByteOffsetForArgs);
    
    void STDMETHODCALLTYPE Dispatch(
            UINT            ThreadGroupCountX,
            UINT            ThreadGroupCountY,
            UINT            ThreadGroupCountZ);
    
    void STDMETHODCALLTYPE DispatchIndirect(
            ID3D11Buffer*   pBufferForArgs,
            UINT            AlignedByteOffsetForArgs);
    
    void STDMETHODCALLTYPE IASetInputLayout(
            ID3D11InputLayout*                pInputLayout);
    
    void STDMETHODCALLTYPE IASetPrimitiveTopology(
            D3D11_PRIMITIVE_TOPOLOGY          Topology);
    
    void STDMETHODCALLTYPE IASetVertexBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppVertexBuffers,
      const UINT*                             pStrides,
      const UINT*                             pOffsets);
    
    void STDMETHODCALLTYPE IASetIndexBuffer(
            ID3D11Buffer*                     pIndexBuffer,
            DXGI_FORMAT                       Format,
            UINT                              Offset);
    
    void STDMETHODCALLTYPE IAGetInputLayout(
            ID3D11InputLayout**               ppInputLayout);
    
    void STDMETHODCALLTYPE IAGetPrimitiveTopology(
            D3D11_PRIMITIVE_TOPOLOGY*         pTopology);
    
    void STDMETHODCALLTYPE IAGetVertexBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppVertexBuffers,
            UINT*                             pStrides,
            UINT*                             pOffsets);
    
    void STDMETHODCALLTYPE IAGetIndexBuffer(
            ID3D11Buffer**                    ppIndexBuffer,
            DXGI_FORMAT*                      pFormat,
            UINT*                             pOffset);
    
    void STDMETHODCALLTYPE VSSetShader(
            ID3D11VertexShader*               pVertexShader,
            ID3D11ClassInstance* const*       ppClassInstances,
            UINT                              NumClassInstances);
    
    void STDMETHODCALLTYPE VSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers);

     void STDMETHODCALLTYPE VSSetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers,
      const UINT*                             pFirstConstant,
      const UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE VSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView* const*  ppShaderResourceViews);
    
    void STDMETHODCALLTYPE VSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState* const*        ppSamplers);
    
    void STDMETHODCALLTYPE VSGetShader(
            ID3D11VertexShader**              ppVertexShader,
            ID3D11ClassInstance**             ppClassInstances,
            UINT*                             pNumClassInstances);
    
    void STDMETHODCALLTYPE VSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers);

    void STDMETHODCALLTYPE VSGetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers,
            UINT*                             pFirstConstant,
            UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE VSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView**        ppShaderResourceViews);
    
    void STDMETHODCALLTYPE VSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState**              ppSamplers);
    
    void STDMETHODCALLTYPE HSSetShader(
            ID3D11HullShader*                 pHullShader,
            ID3D11ClassInstance* const*       ppClassInstances,
            UINT                              NumClassInstances);
    
    void STDMETHODCALLTYPE HSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView* const*  ppShaderResourceViews);
    
    void STDMETHODCALLTYPE HSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers);
    
    void STDMETHODCALLTYPE HSSetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers,
      const UINT*                             pFirstConstant,
      const UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE HSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState* const*        ppSamplers);
    
    void STDMETHODCALLTYPE HSGetShader(
            ID3D11HullShader**                ppHullShader,
            ID3D11ClassInstance**             ppClassInstances,
            UINT*                             pNumClassInstances);
    
    void STDMETHODCALLTYPE HSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers);

     void STDMETHODCALLTYPE HSGetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers,
            UINT*                             pFirstConstant,
            UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE HSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView**        ppShaderResourceViews);
    
    void STDMETHODCALLTYPE HSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState**              ppSamplers);
    
    void STDMETHODCALLTYPE DSSetShader(
            ID3D11DomainShader*               pDomainShader,
            ID3D11ClassInstance* const*       ppClassInstances,
            UINT                              NumClassInstances);
    
    void STDMETHODCALLTYPE DSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView* const*  ppShaderResourceViews);
    
    void STDMETHODCALLTYPE DSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers);

    void STDMETHODCALLTYPE DSSetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers,
      const UINT*                             pFirstConstant,
      const UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE DSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState* const*        ppSamplers);
    
    void STDMETHODCALLTYPE DSGetShader(
            ID3D11DomainShader**              ppDomainShader,
            ID3D11ClassInstance**             ppClassInstances,
            UINT*                             pNumClassInstances);
    
    void STDMETHODCALLTYPE DSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers);
    
     void STDMETHODCALLTYPE DSGetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers,
            UINT*                             pFirstConstant,
            UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE DSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView**        ppShaderResourceViews);
    
    void STDMETHODCALLTYPE DSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState**              ppSamplers);
    
    void STDMETHODCALLTYPE GSSetShader(
            ID3D11GeometryShader*             pShader,
            ID3D11ClassInstance* const*       ppClassInstances,
            UINT                              NumClassInstances);
    
    void STDMETHODCALLTYPE GSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers);
    
    void STDMETHODCALLTYPE GSSetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers,
      const UINT*                             pFirstConstant,
      const UINT*                             pNumConstants);

    void STDMETHODCALLTYPE GSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView* const*  ppShaderResourceViews);
    
    void STDMETHODCALLTYPE GSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState* const*        ppSamplers);
    
    void STDMETHODCALLTYPE GSGetShader(
            ID3D11GeometryShader**            ppGeometryShader,
            ID3D11ClassInstance**             ppClassInstances,
            UINT*                             pNumClassInstances);
    
    void STDMETHODCALLTYPE GSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers);
    
     void STDMETHODCALLTYPE GSGetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers,
            UINT*                             pFirstConstant,
            UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE GSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView**        ppShaderResourceViews);
    
    void STDMETHODCALLTYPE GSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState**              ppSamplers);
    
    void STDMETHODCALLTYPE PSSetShader(
            ID3D11PixelShader*                pPixelShader,
            ID3D11ClassInstance* const*       ppClassInstances,
            UINT                              NumClassInstances);
    
    void STDMETHODCALLTYPE PSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers);

    void STDMETHODCALLTYPE PSSetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers,
      const UINT*                             pFirstConstant,
      const UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE PSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView* const*  ppShaderResourceViews);
    
    void STDMETHODCALLTYPE PSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState* const*        ppSamplers);
    
    void STDMETHODCALLTYPE PSGetShader(
            ID3D11PixelShader**               ppPixelShader,
            ID3D11ClassInstance**             ppClassInstances,
            UINT*                             pNumClassInstances);
    
    void STDMETHODCALLTYPE PSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers);
    
    void STDMETHODCALLTYPE PSGetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers,
            UINT*                             pFirstConstant,
            UINT*                             pNumConstants);

    void STDMETHODCALLTYPE PSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView**        ppShaderResourceViews);
    
    void STDMETHODCALLTYPE PSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState**              ppSamplers);
    
    void STDMETHODCALLTYPE CSSetShader(
            ID3D11ComputeShader*              pComputeShader,
            ID3D11ClassInstance* const*       ppClassInstances,
            UINT                              NumClassInstances);
    
    void STDMETHODCALLTYPE CSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers);
    
    void STDMETHODCALLTYPE CSSetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers,
      const UINT*                             pFirstConstant,
      const UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE CSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView* const*  ppShaderResourceViews);
    
    void STDMETHODCALLTYPE CSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState* const*        ppSamplers);
    
    void STDMETHODCALLTYPE CSSetUnorderedAccessViews(
            UINT                              StartSlot,
            UINT                              NumUAVs,
            ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
      const UINT*                             pUAVInitialCounts);
    
    void STDMETHODCALLTYPE CSGetShader(
            ID3D11ComputeShader**             ppComputeShader,
            ID3D11ClassInstance**             ppClassInstances,
            UINT*                             pNumClassInstances);
    
    void STDMETHODCALLTYPE CSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers);
    
    void STDMETHODCALLTYPE CSGetConstantBuffers1(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers,
            UINT*                             pFirstConstant,
            UINT*                             pNumConstants);
    
    void STDMETHODCALLTYPE CSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView**        ppShaderResourceViews);
    
    void STDMETHODCALLTYPE CSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState**              ppSamplers);
    
    void STDMETHODCALLTYPE CSGetUnorderedAccessViews(
            UINT                              StartSlot,
            UINT                              NumUAVs,
            ID3D11UnorderedAccessView**       ppUnorderedAccessViews);
    
    void STDMETHODCALLTYPE OMSetRenderTargets(
            UINT                              NumViews,
            ID3D11RenderTargetView* const*    ppRenderTargetViews,
            ID3D11DepthStencilView*           pDepthStencilView);
    
    void STDMETHODCALLTYPE OMSetRenderTargetsAndUnorderedAccessViews(
            UINT                              NumRTVs,
            ID3D11RenderTargetView* const*    ppRenderTargetViews,
            ID3D11DepthStencilView*           pDepthStencilView,
            UINT                              UAVStartSlot,
            UINT                              NumUAVs,
            ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
      const UINT*                             pUAVInitialCounts);
    
    void STDMETHODCALLTYPE OMSetBlendState(
            ID3D11BlendState*                 pBlendState,
      const FLOAT                             BlendFactor[4],
            UINT                              SampleMask);
    
    void STDMETHODCALLTYPE OMSetDepthStencilState(
            ID3D11DepthStencilState*          pDepthStencilState,
            UINT                              StencilRef);
    
    void STDMETHODCALLTYPE OMGetRenderTargets(
            UINT                              NumViews,
            ID3D11RenderTargetView**          ppRenderTargetViews,
            ID3D11DepthStencilView**          ppDepthStencilView);
    
    void STDMETHODCALLTYPE OMGetRenderTargetsAndUnorderedAccessViews(
            UINT                              NumRTVs,
            ID3D11RenderTargetView**          ppRenderTargetViews,
            ID3D11DepthStencilView**          ppDepthStencilView,
            UINT                              UAVStartSlot,
            UINT                              NumUAVs,
            ID3D11UnorderedAccessView**       ppUnorderedAccessViews);
    
    void STDMETHODCALLTYPE OMGetBlendState(
            ID3D11BlendState**                ppBlendState,
            FLOAT                             BlendFactor[4],
            UINT*                             pSampleMask);
    
    void STDMETHODCALLTYPE OMGetDepthStencilState(
            ID3D11DepthStencilState**         ppDepthStencilState,
            UINT*                             pStencilRef);
    
    void STDMETHODCALLTYPE RSSetState(
            ID3D11RasterizerState*            pRasterizerState);
    
    void STDMETHODCALLTYPE RSSetViewports(
            UINT                              NumViewports,
      const D3D11_VIEWPORT*                   pViewports);
    
    void STDMETHODCALLTYPE RSSetScissorRects(
            UINT                              NumRects,
      const D3D11_RECT*                       pRects);
    
    void STDMETHODCALLTYPE RSGetState(
            ID3D11RasterizerState**           ppRasterizerState);
    
    void STDMETHODCALLTYPE RSGetViewports(
            UINT*                             pNumViewports,
            D3D11_VIEWPORT*                   pViewports);
    
    void STDMETHODCALLTYPE RSGetScissorRects(
            UINT*                             pNumRects,
            D3D11_RECT*                       pRects);
    
    void STDMETHODCALLTYPE SOSetTargets(
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppSOTargets,
      const UINT*                             pOffsets);
    
    void STDMETHODCALLTYPE SOGetTargets(
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppSOTargets);
    
    void STDMETHODCALLTYPE SOGetTargetsWithOffsets(
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppSOTargets,
            UINT*                             pOffsets);
    
    BOOL STDMETHODCALLTYPE IsAnnotationEnabled();

    void STDMETHODCALLTYPE SetMarkerInt(
            LPCWSTR                           pLabel,
            INT                               Data);

    void STDMETHODCALLTYPE BeginEventInt(
            LPCWSTR                           pLabel,
            INT                               Data);

    void STDMETHODCALLTYPE EndEvent();

    void STDMETHODCALLTYPE GetHardwareProtectionState(
            BOOL*                             pHwProtectionEnable);
    
    void STDMETHODCALLTYPE SetHardwareProtectionState(
            BOOL                              HwProtectionEnable);

  protected:
    
    D3D11UserDefinedAnnotation  m_annotation;
    D3D11ContextState           m_state;

    void SetDrawBuffers(
            ID3D11Buffer*                     pBufferForArgs,
            ID3D11Buffer*                     pBufferForCount);

    void SetConstantBuffers(
            D3D11ConstantBufferBindings&      Bindings,
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers);

    void SetConstantBuffers1(
            D3D11ConstantBufferBindings&      Bindings,
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer* const*              ppConstantBuffers,
      const UINT*                             pFirstConstant,
      const UINT*                             pNumConstants);

    void SetSamplers(
            D3D11SamplerBindings&             Bindings,
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState* const*        ppSamplers);

    void SetShaderResources(
            D3D11ShaderResourceBindings&      Bindings,
            UINT                              StartSlot,
            UINT                              NumResources,
            ID3D11ShaderResourceView* const*  ppResources);
    
    void GetConstantBuffers(
      const D3D11ConstantBufferBindings&      Bindings,
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D11Buffer**                    ppConstantBuffers, 
            UINT*                             pFirstConstant, 
            UINT*                             pNumConstants);

    void GetShaderResources(
      const D3D11ShaderResourceBindings&      Bindings,
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D11ShaderResourceView**        ppShaderResourceViews);

    void GetSamplers(
      const D3D11SamplerBindings&             Bindings,
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D11SamplerState**              ppSamplers);

  };
  
}
