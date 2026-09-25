// Copyright (c) 2025 Hans-Kristian Arntzen
// SPDX-License-Identifier: MIT
#pragma once

#include <stdint.h>

namespace Vulkan
{
class ImageView;
}

namespace PyroWave
{
struct ViewBuffers
{
	const Vulkan::ImageView *planes[3];
};

enum class ChromaSubsampling
{
	Chroma420,
	Chroma444
};

// The colour fields of a frame's sequence header. Each holds its field's one bit value, as
// the COLOR_PRIMARIES_*, TRANSFER_FUNCTION_*, YCBCR_TRANSFORM_*, YCBCR_RANGE_* and
// CHROMA_SITING_* enums define it. A zero-initialised value is what the encoder writes
// until it is given a colour.
struct BitstreamColor
{
	uint8_t color_primaries : 1;
	uint8_t transfer_function : 1;
	uint8_t ycbcr_transform : 1;
	uint8_t ycbcr_range : 1;
	uint8_t chroma_siting : 1;
};
}
