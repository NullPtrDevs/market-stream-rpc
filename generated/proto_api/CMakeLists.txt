# Proto dir and file path
set(PROTO_DIR "${PROJECT_SOURCE_DIR}/api_contracts/proto/market-stream")
set(PROTO_FILE "${PROTO_DIR}/market_data.proto")

# Generated files dir
set(GEN_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
file(MAKE_DIRECTORY ${GEN_DIR})

# Setup generated files
set(PROTO_SRCS "${GEN_DIR}/market_data.pb.cc")
set(PROTO_HDRS "${GEN_DIR}/market_data.pb.h")
set(GRPC_SRCS  "${GEN_DIR}/market_data.grpc.pb.cc")
set(GRPC_HDRS  "${GEN_DIR}/market_data.grpc.pb.h")


set(PROTOC_EXE $<TARGET_FILE:protobuf::protoc>)
set(GRPC_CPP_PLUGIN_EXE $<TARGET_FILE:grpc_cpp_plugin>)

# Generate C++ classes from protobuf files
add_custom_command(
    OUTPUT ${PROTO_SRCS} ${PROTO_HDRS} ${GRPC_SRCS} ${GRPC_HDRS}
    COMMAND ${PROTOC_EXE}
    ARGS --proto_path=${PROTO_DIR}
         --cpp_out=${GEN_DIR}
         --grpc_out=${GEN_DIR}
         --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_EXE}
         ${PROTO_FILE}
    DEPENDS ${PROTO_FILE}
    COMMENT "CPM: Generate C++ classes from gRPC protobuf file"
)

# Create temporary file to build static library
set(TEMPORARY_CPP "${CMAKE_CURRENT_BINARY_DIR}/placeholder.cpp")
if(NOT EXISTS ${TEMPORARY_CPP})
    file(WRITE ${TEMPORARY_CPP} "// Auto-generated stub for static library linking\n")
endif()

# Create library
add_library(generated_api STATIC 
    ${TEMPORARY_CPP} 
    ${PROTO_SRCS} 
    ${GRPC_SRCS}
)

target_include_directories(generated_api PUBLIC ${GEN_DIR})
target_link_libraries(generated_api PUBLIC grpc++ protobuf::libprotobuf)