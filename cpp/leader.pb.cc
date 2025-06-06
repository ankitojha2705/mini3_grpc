// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: leader.proto

#include "leader.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace leader {
PROTOBUF_CONSTEXPR NodeStatus::NodeStatus(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.node_id_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.score_)*/0
  , /*decltype(_impl_.queue_length_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct NodeStatusDefaultTypeInternal {
  PROTOBUF_CONSTEXPR NodeStatusDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~NodeStatusDefaultTypeInternal() {}
  union {
    NodeStatus _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 NodeStatusDefaultTypeInternal _NodeStatus_default_instance_;
PROTOBUF_CONSTEXPR Task::Task(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.task_id_)*/0
  , /*decltype(_impl_.duration_ms_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct TaskDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TaskDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~TaskDefaultTypeInternal() {}
  union {
    Task _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TaskDefaultTypeInternal _Task_default_instance_;
PROTOBUF_CONSTEXPR Ack::Ack(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.message_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct AckDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AckDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~AckDefaultTypeInternal() {}
  union {
    Ack _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AckDefaultTypeInternal _Ack_default_instance_;
}  // namespace leader
static ::_pb::Metadata file_level_metadata_leader_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_leader_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_leader_2eproto = nullptr;

const uint32_t TableStruct_leader_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::leader::NodeStatus, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::leader::NodeStatus, _impl_.node_id_),
  PROTOBUF_FIELD_OFFSET(::leader::NodeStatus, _impl_.score_),
  PROTOBUF_FIELD_OFFSET(::leader::NodeStatus, _impl_.queue_length_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::leader::Task, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::leader::Task, _impl_.task_id_),
  PROTOBUF_FIELD_OFFSET(::leader::Task, _impl_.duration_ms_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::leader::Ack, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::leader::Ack, _impl_.message_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::leader::NodeStatus)},
  { 9, -1, -1, sizeof(::leader::Task)},
  { 17, -1, -1, sizeof(::leader::Ack)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::leader::_NodeStatus_default_instance_._instance,
  &::leader::_Task_default_instance_._instance,
  &::leader::_Ack_default_instance_._instance,
};

const char descriptor_table_protodef_leader_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014leader.proto\022\006leader\"B\n\nNodeStatus\022\017\n\007"
  "node_id\030\001 \001(\t\022\r\n\005score\030\002 \001(\002\022\024\n\014queue_le"
  "ngth\030\003 \001(\005\",\n\004Task\022\017\n\007task_id\030\001 \001(\005\022\023\n\013d"
  "uration_ms\030\002 \001(\005\"\026\n\003Ack\022\017\n\007message\030\001 \001(\t"
  "2h\n\013NodeService\022.\n\tHeartbeat\022\022.leader.No"
  "deStatus\032\013.leader.Ack\"\000\022)\n\nAssignTask\022\014."
  "leader.Task\032\013.leader.Ack\"\000b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_leader_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_leader_2eproto = {
    false, false, 274, descriptor_table_protodef_leader_2eproto,
    "leader.proto",
    &descriptor_table_leader_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_leader_2eproto::offsets,
    file_level_metadata_leader_2eproto, file_level_enum_descriptors_leader_2eproto,
    file_level_service_descriptors_leader_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_leader_2eproto_getter() {
  return &descriptor_table_leader_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_leader_2eproto(&descriptor_table_leader_2eproto);
namespace leader {

// ===================================================================

class NodeStatus::_Internal {
 public:
};

NodeStatus::NodeStatus(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:leader.NodeStatus)
}
NodeStatus::NodeStatus(const NodeStatus& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  NodeStatus* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.node_id_){}
    , decltype(_impl_.score_){}
    , decltype(_impl_.queue_length_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.node_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.node_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_node_id().empty()) {
    _this->_impl_.node_id_.Set(from._internal_node_id(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.score_, &from._impl_.score_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.queue_length_) -
    reinterpret_cast<char*>(&_impl_.score_)) + sizeof(_impl_.queue_length_));
  // @@protoc_insertion_point(copy_constructor:leader.NodeStatus)
}

inline void NodeStatus::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.node_id_){}
    , decltype(_impl_.score_){0}
    , decltype(_impl_.queue_length_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.node_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.node_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

NodeStatus::~NodeStatus() {
  // @@protoc_insertion_point(destructor:leader.NodeStatus)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void NodeStatus::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.node_id_.Destroy();
}

void NodeStatus::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void NodeStatus::Clear() {
// @@protoc_insertion_point(message_clear_start:leader.NodeStatus)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.node_id_.ClearToEmpty();
  ::memset(&_impl_.score_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.queue_length_) -
      reinterpret_cast<char*>(&_impl_.score_)) + sizeof(_impl_.queue_length_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* NodeStatus::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string node_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_node_id();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "leader.NodeStatus.node_id"));
        } else
          goto handle_unusual;
        continue;
      // float score = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 21)) {
          _impl_.score_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // int32 queue_length = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.queue_length_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* NodeStatus::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:leader.NodeStatus)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string node_id = 1;
  if (!this->_internal_node_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_node_id().data(), static_cast<int>(this->_internal_node_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "leader.NodeStatus.node_id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_node_id(), target);
  }

  // float score = 2;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_score = this->_internal_score();
  uint32_t raw_score;
  memcpy(&raw_score, &tmp_score, sizeof(tmp_score));
  if (raw_score != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(2, this->_internal_score(), target);
  }

  // int32 queue_length = 3;
  if (this->_internal_queue_length() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_queue_length(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:leader.NodeStatus)
  return target;
}

size_t NodeStatus::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:leader.NodeStatus)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string node_id = 1;
  if (!this->_internal_node_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_node_id());
  }

  // float score = 2;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_score = this->_internal_score();
  uint32_t raw_score;
  memcpy(&raw_score, &tmp_score, sizeof(tmp_score));
  if (raw_score != 0) {
    total_size += 1 + 4;
  }

  // int32 queue_length = 3;
  if (this->_internal_queue_length() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_queue_length());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData NodeStatus::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    NodeStatus::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*NodeStatus::GetClassData() const { return &_class_data_; }


void NodeStatus::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<NodeStatus*>(&to_msg);
  auto& from = static_cast<const NodeStatus&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:leader.NodeStatus)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_node_id().empty()) {
    _this->_internal_set_node_id(from._internal_node_id());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_score = from._internal_score();
  uint32_t raw_score;
  memcpy(&raw_score, &tmp_score, sizeof(tmp_score));
  if (raw_score != 0) {
    _this->_internal_set_score(from._internal_score());
  }
  if (from._internal_queue_length() != 0) {
    _this->_internal_set_queue_length(from._internal_queue_length());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void NodeStatus::CopyFrom(const NodeStatus& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:leader.NodeStatus)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NodeStatus::IsInitialized() const {
  return true;
}

void NodeStatus::InternalSwap(NodeStatus* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.node_id_, lhs_arena,
      &other->_impl_.node_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(NodeStatus, _impl_.queue_length_)
      + sizeof(NodeStatus::_impl_.queue_length_)
      - PROTOBUF_FIELD_OFFSET(NodeStatus, _impl_.score_)>(
          reinterpret_cast<char*>(&_impl_.score_),
          reinterpret_cast<char*>(&other->_impl_.score_));
}

::PROTOBUF_NAMESPACE_ID::Metadata NodeStatus::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_leader_2eproto_getter, &descriptor_table_leader_2eproto_once,
      file_level_metadata_leader_2eproto[0]);
}

// ===================================================================

class Task::_Internal {
 public:
};

Task::Task(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:leader.Task)
}
Task::Task(const Task& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Task* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.task_id_){}
    , decltype(_impl_.duration_ms_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.task_id_, &from._impl_.task_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.duration_ms_) -
    reinterpret_cast<char*>(&_impl_.task_id_)) + sizeof(_impl_.duration_ms_));
  // @@protoc_insertion_point(copy_constructor:leader.Task)
}

inline void Task::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.task_id_){0}
    , decltype(_impl_.duration_ms_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Task::~Task() {
  // @@protoc_insertion_point(destructor:leader.Task)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Task::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Task::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Task::Clear() {
// @@protoc_insertion_point(message_clear_start:leader.Task)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.task_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.duration_ms_) -
      reinterpret_cast<char*>(&_impl_.task_id_)) + sizeof(_impl_.duration_ms_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Task::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 task_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.task_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 duration_ms = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.duration_ms_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Task::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:leader.Task)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 task_id = 1;
  if (this->_internal_task_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_task_id(), target);
  }

  // int32 duration_ms = 2;
  if (this->_internal_duration_ms() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_duration_ms(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:leader.Task)
  return target;
}

size_t Task::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:leader.Task)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 task_id = 1;
  if (this->_internal_task_id() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_task_id());
  }

  // int32 duration_ms = 2;
  if (this->_internal_duration_ms() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_duration_ms());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Task::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Task::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Task::GetClassData() const { return &_class_data_; }


void Task::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Task*>(&to_msg);
  auto& from = static_cast<const Task&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:leader.Task)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_task_id() != 0) {
    _this->_internal_set_task_id(from._internal_task_id());
  }
  if (from._internal_duration_ms() != 0) {
    _this->_internal_set_duration_ms(from._internal_duration_ms());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Task::CopyFrom(const Task& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:leader.Task)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Task::IsInitialized() const {
  return true;
}

void Task::InternalSwap(Task* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Task, _impl_.duration_ms_)
      + sizeof(Task::_impl_.duration_ms_)
      - PROTOBUF_FIELD_OFFSET(Task, _impl_.task_id_)>(
          reinterpret_cast<char*>(&_impl_.task_id_),
          reinterpret_cast<char*>(&other->_impl_.task_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Task::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_leader_2eproto_getter, &descriptor_table_leader_2eproto_once,
      file_level_metadata_leader_2eproto[1]);
}

// ===================================================================

class Ack::_Internal {
 public:
};

Ack::Ack(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:leader.Ack)
}
Ack::Ack(const Ack& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Ack* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.message_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.message_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.message_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_message().empty()) {
    _this->_impl_.message_.Set(from._internal_message(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:leader.Ack)
}

inline void Ack::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.message_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.message_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.message_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Ack::~Ack() {
  // @@protoc_insertion_point(destructor:leader.Ack)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Ack::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.message_.Destroy();
}

void Ack::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Ack::Clear() {
// @@protoc_insertion_point(message_clear_start:leader.Ack)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.message_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Ack::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string message = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_message();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "leader.Ack.message"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Ack::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:leader.Ack)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string message = 1;
  if (!this->_internal_message().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_message().data(), static_cast<int>(this->_internal_message().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "leader.Ack.message");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_message(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:leader.Ack)
  return target;
}

size_t Ack::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:leader.Ack)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string message = 1;
  if (!this->_internal_message().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_message());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Ack::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Ack::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Ack::GetClassData() const { return &_class_data_; }


void Ack::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Ack*>(&to_msg);
  auto& from = static_cast<const Ack&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:leader.Ack)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_message().empty()) {
    _this->_internal_set_message(from._internal_message());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Ack::CopyFrom(const Ack& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:leader.Ack)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Ack::IsInitialized() const {
  return true;
}

void Ack::InternalSwap(Ack* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.message_, lhs_arena,
      &other->_impl_.message_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata Ack::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_leader_2eproto_getter, &descriptor_table_leader_2eproto_once,
      file_level_metadata_leader_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace leader
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::leader::NodeStatus*
Arena::CreateMaybeMessage< ::leader::NodeStatus >(Arena* arena) {
  return Arena::CreateMessageInternal< ::leader::NodeStatus >(arena);
}
template<> PROTOBUF_NOINLINE ::leader::Task*
Arena::CreateMaybeMessage< ::leader::Task >(Arena* arena) {
  return Arena::CreateMessageInternal< ::leader::Task >(arena);
}
template<> PROTOBUF_NOINLINE ::leader::Ack*
Arena::CreateMaybeMessage< ::leader::Ack >(Arena* arena) {
  return Arena::CreateMessageInternal< ::leader::Ack >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
