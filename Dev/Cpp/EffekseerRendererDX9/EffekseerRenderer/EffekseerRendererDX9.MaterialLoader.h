﻿
#ifndef __EFFEKSEERRENDERER_DX9_MATERIALLOADER_H__
#define __EFFEKSEERRENDERER_DX9_MATERIALLOADER_H__

#include "EffekseerRendererDX9.DeviceObject.h"
#include "EffekseerRendererDX9.RendererImplemented.h"
#include <memory>

namespace Effekseer
{
class Material;
class CompiledMaterialBinary;
} // namespace Effekseer

namespace EffekseerRendererDX9
{

class MaterialLoader : public ::Effekseer::MaterialLoader
{
private:
	Backend::GraphicsDeviceRef graphicsDevice_ = nullptr;
	::Effekseer::FileInterfaceRef fileInterface_ = nullptr;

	::Effekseer::MaterialRef LoadAcutually(::Effekseer::MaterialFile& materialFile, ::Effekseer::CompiledMaterialBinary* binary);

public:
	MaterialLoader(const Backend::GraphicsDeviceRef graphicsDevice, ::Effekseer::FileInterfaceRef fileInterface);
	virtual ~MaterialLoader();

	::Effekseer::MaterialRef Load(const char16_t* path) override;

	::Effekseer::MaterialRef Load(const void* data, int32_t size, Effekseer::MaterialFileType fileType) override;

	void Unload(::Effekseer::MaterialRef data) override;
};

} // namespace EffekseerRendererDX9

#endif // __EFFEKSEERRENDERER_GL_MODELLOADER_H__
