// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sum.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_sum_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_sum_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_sum_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_sum_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_sum_2eproto;
namespace pbsum {
class Add;
struct AddDefaultTypeInternal;
extern AddDefaultTypeInternal _Add_default_instance_;
class LocalSum;
struct LocalSumDefaultTypeInternal;
extern LocalSumDefaultTypeInternal _LocalSum_default_instance_;
}  // namespace pbsum
PROTOBUF_NAMESPACE_OPEN
template<> ::pbsum::Add* Arena::CreateMaybeMessage<::pbsum::Add>(Arena*);
template<> ::pbsum::LocalSum* Arena::CreateMaybeMessage<::pbsum::LocalSum>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace pbsum {

enum MessageCode : int {
  NONE = 0,
  ADD = 1,
  LOCAL_SUM = 2,
  MessageCode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  MessageCode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool MessageCode_IsValid(int value);
constexpr MessageCode MessageCode_MIN = NONE;
constexpr MessageCode MessageCode_MAX = LOCAL_SUM;
constexpr int MessageCode_ARRAYSIZE = MessageCode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageCode_descriptor();
template<typename T>
inline const std::string& MessageCode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, MessageCode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function MessageCode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    MessageCode_descriptor(), enum_t_value);
}
inline bool MessageCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, MessageCode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<MessageCode>(
    MessageCode_descriptor(), name, value);
}
// ===================================================================

class Add final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pbsum.Add) */ {
 public:
  inline Add() : Add(nullptr) {}
  ~Add() override;
  explicit PROTOBUF_CONSTEXPR Add(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Add(const Add& from);
  Add(Add&& from) noexcept
    : Add() {
    *this = ::std::move(from);
  }

  inline Add& operator=(const Add& from) {
    CopyFrom(from);
    return *this;
  }
  inline Add& operator=(Add&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Add& default_instance() {
    return *internal_default_instance();
  }
  static inline const Add* internal_default_instance() {
    return reinterpret_cast<const Add*>(
               &_Add_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Add& a, Add& b) {
    a.Swap(&b);
  }
  inline void Swap(Add* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Add* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Add* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Add>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Add& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Add& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Add* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pbsum.Add";
  }
  protected:
  explicit Add(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNumFieldNumber = 1,
  };
  // int32 num = 1;
  void clear_num();
  int32_t num() const;
  void set_num(int32_t value);
  private:
  int32_t _internal_num() const;
  void _internal_set_num(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:pbsum.Add)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int32_t num_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_sum_2eproto;
};
// -------------------------------------------------------------------

class LocalSum final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pbsum.LocalSum) */ {
 public:
  inline LocalSum() : LocalSum(nullptr) {}
  ~LocalSum() override;
  explicit PROTOBUF_CONSTEXPR LocalSum(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LocalSum(const LocalSum& from);
  LocalSum(LocalSum&& from) noexcept
    : LocalSum() {
    *this = ::std::move(from);
  }

  inline LocalSum& operator=(const LocalSum& from) {
    CopyFrom(from);
    return *this;
  }
  inline LocalSum& operator=(LocalSum&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const LocalSum& default_instance() {
    return *internal_default_instance();
  }
  static inline const LocalSum* internal_default_instance() {
    return reinterpret_cast<const LocalSum*>(
               &_LocalSum_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(LocalSum& a, LocalSum& b) {
    a.Swap(&b);
  }
  inline void Swap(LocalSum* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LocalSum* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LocalSum* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LocalSum>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LocalSum& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const LocalSum& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LocalSum* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pbsum.LocalSum";
  }
  protected:
  explicit LocalSum(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSumFieldNumber = 1,
  };
  // int32 sum = 1;
  void clear_sum();
  int32_t sum() const;
  void set_sum(int32_t value);
  private:
  int32_t _internal_sum() const;
  void _internal_set_sum(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:pbsum.LocalSum)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int32_t sum_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_sum_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Add

// int32 num = 1;
inline void Add::clear_num() {
  num_ = 0;
}
inline int32_t Add::_internal_num() const {
  return num_;
}
inline int32_t Add::num() const {
  // @@protoc_insertion_point(field_get:pbsum.Add.num)
  return _internal_num();
}
inline void Add::_internal_set_num(int32_t value) {
  
  num_ = value;
}
inline void Add::set_num(int32_t value) {
  _internal_set_num(value);
  // @@protoc_insertion_point(field_set:pbsum.Add.num)
}

// -------------------------------------------------------------------

// LocalSum

// int32 sum = 1;
inline void LocalSum::clear_sum() {
  sum_ = 0;
}
inline int32_t LocalSum::_internal_sum() const {
  return sum_;
}
inline int32_t LocalSum::sum() const {
  // @@protoc_insertion_point(field_get:pbsum.LocalSum.sum)
  return _internal_sum();
}
inline void LocalSum::_internal_set_sum(int32_t value) {
  
  sum_ = value;
}
inline void LocalSum::set_sum(int32_t value) {
  _internal_set_sum(value);
  // @@protoc_insertion_point(field_set:pbsum.LocalSum.sum)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace pbsum

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::pbsum::MessageCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::pbsum::MessageCode>() {
  return ::pbsum::MessageCode_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_sum_2eproto