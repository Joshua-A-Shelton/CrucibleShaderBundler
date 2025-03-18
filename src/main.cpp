#include <filesystem>
#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/endian/conversion.hpp>
namespace po = boost::program_options;

bool isValidColorTarget(const std::string colorTarget)
{
    if( colorTarget == "R32G32B32A32_FLOAT"){return true;}
    else if( colorTarget == "R32G32B32A32_UINT"){return true;}
    else if( colorTarget == "R32G32B32A32_SINT"){return true;}
    else if( colorTarget == "R32G32B32_FLOAT"){return true;}
    else if( colorTarget == "R32G32B32_UINT"){return true;}
    else if( colorTarget == "R32G32B32_SINT"){return true;}
    else if( colorTarget == "R16G16B16A16_FLOAT"){return true;}
    else if( colorTarget == "R16G16B16A16_UNORM"){return true;}
    else if( colorTarget == "R16G16B16A16_UINT"){return true;}
    else if( colorTarget == "R16G16B16A16_SNORM"){return true;}
    else if( colorTarget == "R16G16B16A16_SINT"){return true;}
    else if( colorTarget == "R32G32_FLOAT"){return true;}
    else if( colorTarget == "R32G32_UINT"){return true;}
    else if( colorTarget == "R32G32_SINT"){return true;}
    else if( colorTarget == "R10G10B10A2_UNORM"){return true;}
    else if( colorTarget == "R10G10B10A2_UINT"){return true;}
    else if( colorTarget == "R11G11B10_FLOAT"){return true;}
    else if( colorTarget == "R8G8B8A8_UNORM"){return true;}
    else if( colorTarget == "R8G8B8A8_UNORM_SRGB"){return true;}
    else if( colorTarget == "R8G8B8A8_UINT"){return true;}
    else if( colorTarget == "R8G8B8A8_SNORM"){return true;}
    else if( colorTarget == "R8G8B8A8_SINT"){return true;}
    else if( colorTarget == "R16G16_FLOAT"){return true;}
    else if( colorTarget == "R16G16_UNORM"){return true;}
    else if( colorTarget == "R16G16_UINT"){return true;}
    else if( colorTarget == "R16G16_SNORM"){return true;}
    else if( colorTarget == "R16G16_SINT"){return true;}
    else if( colorTarget == "R32_FLOAT"){return true;}
    else if( colorTarget == "R32_UINT"){return true;}
    else if( colorTarget == "R32_SINT"){return true;}
    else if( colorTarget == "R8G8_UNORM"){return true;}
    else if( colorTarget == "R8G8_UINT"){return true;}
    else if( colorTarget == "R8G8_SNORM"){return true;}
    else if( colorTarget == "R8G8_SINT"){return true;}
    else if( colorTarget == "R16_FLOAT"){return true;}
    else if( colorTarget == "R16_UNORM"){return true;}
    else if( colorTarget == "R16_UINT"){return true;}
    else if( colorTarget == "R16_SNORM"){return true;}
    else if( colorTarget == "R16_SINT"){return true;}
    else if( colorTarget == "R8_UNORM"){return true;}
    else if( colorTarget == "R8_UINT"){return true;}
    else if( colorTarget == "R8_SNORM"){return true;}
    else if( colorTarget == "R8_SINT"){return true;}
    else if( colorTarget == "A8_UNORM"){return true;}
    else if( colorTarget == "R9G9B9E5_SHAREDEXP"){return true;}
    else if( colorTarget == "R8G8_B8G8_UNORM"){return true;}
    else if( colorTarget == "G8R8_G8B8_UNORM"){return true;}
    else if( colorTarget == "BC1_UNORM"){return true;}
    else if( colorTarget == "BC1_UNORM_SRGB"){return true;}
    else if( colorTarget == "BC2_UNORM"){return true;}
    else if( colorTarget == "BC2_UNORM_SRGB"){return true;}
    else if( colorTarget == "BC3_UNORM"){return true;}
    else if( colorTarget == "BC3_UNORM_SRGB"){return true;}
    else if( colorTarget == "BC4_UNORM"){return true;}
    else if( colorTarget == "BC4_SNORM"){return true;}
    else if( colorTarget == "BC5_UNORM"){return true;}
    else if( colorTarget == "BC5_SNORM"){return true;}
    else if( colorTarget == "B5G6R5_UNORM"){return true;}
    else if( colorTarget == "B5G5R5A1_UNORM"){return true;}
    else if( colorTarget == "B8G8R8A8_UNORM"){return true;}
    else if( colorTarget == "B8G8R8X8_UNORM"){return true;}
    else if( colorTarget == "B8G8R8A8_UNORM_SRGB"){return true;}
    else if( colorTarget == "B8G8R8X8_UNORM_SRGB"){return true;}
    else if( colorTarget == "BC6H_UF16"){return true;}
    else if( colorTarget == "BC6H_SF16"){return true;}
    else if( colorTarget == "BC7_UNORM"){return true;}
    else if( colorTarget == "BC7_UNORM_SRGB"){return true;}
    else if( colorTarget == "AYUV"){return true;}
    else if( colorTarget == "NV12"){return true;}
    else if( colorTarget == "OPAQUE_420"){return true;}
    else if( colorTarget == "YUY2"){return true;}
    else if( colorTarget == "B4G4R4A4_UNORM"){return true;}
    return false;

}

bool isValidDepthTarget(const std::string & depthTarget)
{
    if( depthTarget == "D32_FLOAT_S8X24_UINT"){return true;}
    else if( depthTarget == "D32_FLOAT"){return true;}
    else if( depthTarget == "D24_UNORM_S8_UINT"){return true;}
    else if( depthTarget == "D16_UNORM"){return true;}
    else if( depthTarget == "none"){return true;}
    return false;
}

bool isValidVertexAttribute(const std::string & vertexAttribute)
{
    if (vertexAttribute == "POSITION_3D"){return true;}
    else if (vertexAttribute == "POSITION_2D"){return true;}
    else if (vertexAttribute == "NORMAL"){return true;}
    else if (vertexAttribute == "UV"){return true;}
    else if (vertexAttribute == "COLOR"){return true;}
    return false;
}
uint16_t vertexAttributeNumber(const std::vector<std::string> & attributeNames)
{
    uint16_t attributeNumber = 0;
    for (auto& attributeName : attributeNames)
    {
        if (attributeName == "POSITION_3D")
        {
            attributeNumber|=0b0000000000000001;
        }
        else if (attributeName == "POSITION_2D")
        {
            attributeNumber|=0b0000000000000010;
        }
        else if (attributeName == "NORMAL")
        {
            attributeNumber|=0b0000000000000100;
        }
        else if (attributeName == "UV")
        {
            attributeNumber|=0b0000000000001000;
        }
        else if (attributeName == "COLOR")
        {
            attributeNumber|=0b0000000000010000;
        }
    }
    return attributeNumber;
}

std::vector<char> readFile(std::filesystem::path filename)
{
    // open the file:
    std::ifstream file(filename, std::ios::binary);

    // read the data:
    return std::vector<char>((std::istreambuf_iterator<char>(file)),
                              std::istreambuf_iterator<char>());
}

int main(int argc, char**argv)
{
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help,h", "produce help message")
    ("ctarget,c", po::value<std::vector<std::string>>(),"Color Targets of shaders")
    ("dtarget,d", po::value<std::string>()->default_value("none"),"Depth Target of shaders")
    ("vertexAttribs,a", po::value<std::vector<std::string>>(),"Vertex attributes required for the shader")
    ("vertexShader,v", po::value<std::string>(),"Vertex shader spir-v file")
    ("fragmentShader,f", po::value<std::string>(),"Fragment shader spir-v file")
    ("output,o", po::value<std::string>(),"Output file")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc,argv,desc),vm);

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }

    std::vector<std::string>  colorTargets = vm["ctarget"].as<std::vector<std::string>>();
    std::string  depthTarget = vm["dtarget"].as<std::string>();
    std::vector<std::string>  vertexAttributes = vm["vertexAttribs"].as<std::vector<std::string>>();
    std::string  vertexShader = vm["vertexShader"].as<std::string>();
    std::string  fragmentShader = vm["fragmentShader"].as<std::string>();
    std::string  outputFile = vm["output"].as<std::string>();

    for (auto& colorTarget : colorTargets)
    {
        if (!isValidColorTarget(colorTarget))
        {
            throw po::validation_error(po::validation_error::invalid_option_value,"ctarget", colorTarget);
        }
    }
    if (!isValidDepthTarget(depthTarget))
    {
        throw po::validation_error(po::validation_error::invalid_option_value,"dtarget", depthTarget);
    }
    for (auto& vertexAttribute : vertexAttributes)
    {
        if (!isValidVertexAttribute(vertexAttribute))
        {
            throw po::validation_error(po::validation_error::invalid_option_value,"vertexAttribs", vertexAttribute);
        }
    }
    uint16_t attributeNumber = vertexAttributeNumber(vertexAttributes);
    std::filesystem::path vpath = std::filesystem::path(vertexShader);
    if (!exists(vpath))
    {
        throw std::runtime_error("Vertex shader \""+vpath.string()+"\" does not exist");
    }
    std::filesystem::path fpath = std::filesystem::path(fragmentShader);
    if (!exists(fpath))
    {
        throw std::runtime_error("Fragment shader \""+fpath.string()+"\" does not exist");
    }

    auto vertexData = readFile(vpath);
    auto fragmentData = readFile(fpath);

    std::ofstream output(outputFile, std::ios::binary);
    output << "csbf\n";
    for (auto& colorTarget : colorTargets)
    {
        output<<"#color "<<colorTarget<<'\n';
    }
    if (depthTarget != "none")
    {
        output<<"#depth "<<depthTarget<<'\n';
    }
    auto aNumberBigEnd = boost::endian::little_to_native(attributeNumber);
    output.write(reinterpret_cast<char*>(&aNumberBigEnd), sizeof(aNumberBigEnd));
    auto vertexSize =  static_cast<uint32_t>(vertexData.size());
    boost::endian::little_to_native_inplace(vertexSize);
    output<<"vertex:";
    output.write(reinterpret_cast<char*>(&vertexSize), sizeof(vertexSize));
    for (auto& vertexByte : vertexData)
    {
        output << vertexByte;
    }
    auto fragmentSize = static_cast<uint32_t>(fragmentData.size());
    boost::endian::little_to_native_inplace(fragmentSize);
    output<<"fragment:";
    output.write(reinterpret_cast<char*>(&fragmentSize), sizeof(fragmentSize));
    for (auto& fragmentByte : fragmentData)
    {
        output << fragmentByte;
    }
    output.close();

    return 0;
}