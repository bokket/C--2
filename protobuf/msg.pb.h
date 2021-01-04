// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_msg_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_msg_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_msg_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_msg_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_msg_2eproto;
namespace test_2 {
class student;
class studentDefaultTypeInternal;
extern studentDefaultTypeInternal _student_default_instance_;
class usr_info;
class usr_infoDefaultTypeInternal;
extern usr_infoDefaultTypeInternal _usr_info_default_instance_;
class usr_login;
class usr_loginDefaultTypeInternal;
extern usr_loginDefaultTypeInternal _usr_login_default_instance_;
}  // namespace test_2
PROTOBUF_NAMESPACE_OPEN
template<> ::test_2::student* Arena::CreateMaybeMessage<::test_2::student>(Arena*);
template<> ::test_2::usr_info* Arena::CreateMaybeMessage<::test_2::usr_info>(Arena*);
template<> ::test_2::usr_login* Arena::CreateMaybeMessage<::test_2::usr_login>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace test_2 {

// ===================================================================

class usr_login PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:test_2.usr_login) */ {
 public:
  inline usr_login() : usr_login(nullptr) {}
  virtual ~usr_login();

  usr_login(const usr_login& from);
  usr_login(usr_login&& from) noexcept
    : usr_login() {
    *this = ::std::move(from);
  }

  inline usr_login& operator=(const usr_login& from) {
    CopyFrom(from);
    return *this;
  }
  inline usr_login& operator=(usr_login&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const usr_login& default_instance();

  static inline const usr_login* internal_default_instance() {
    return reinterpret_cast<const usr_login*>(
               &_usr_login_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(usr_login& a, usr_login& b) {
    a.Swap(&b);
  }
  inline void Swap(usr_login* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(usr_login* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline usr_login* New() const final {
    return CreateMaybeMessage<usr_login>(nullptr);
  }

  usr_login* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<usr_login>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const usr_login& from);
  void MergeFrom(const usr_login& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(usr_login* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "test_2.usr_login";
  }
  protected:
  explicit usr_login(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_msg_2eproto);
    return ::descriptor_table_msg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUsrnameFieldNumber = 1,
    kUsrpasswdFieldNumber = 2,
  };
  // string usrname = 1;
  void clear_usrname();
  const std::string& usrname() const;
  void set_usrname(const std::string& value);
  void set_usrname(std::string&& value);
  void set_usrname(const char* value);
  void set_usrname(const char* value, size_t size);
  std::string* mutable_usrname();
  std::string* release_usrname();
  void set_allocated_usrname(std::string* usrname);
  private:
  const std::string& _internal_usrname() const;
  void _internal_set_usrname(const std::string& value);
  std::string* _internal_mutable_usrname();
  public:

  // string usrpasswd = 2;
  void clear_usrpasswd();
  const std::string& usrpasswd() const;
  void set_usrpasswd(const std::string& value);
  void set_usrpasswd(std::string&& value);
  void set_usrpasswd(const char* value);
  void set_usrpasswd(const char* value, size_t size);
  std::string* mutable_usrpasswd();
  std::string* release_usrpasswd();
  void set_allocated_usrpasswd(std::string* usrpasswd);
  private:
  const std::string& _internal_usrpasswd() const;
  void _internal_set_usrpasswd(const std::string& value);
  std::string* _internal_mutable_usrpasswd();
  public:

  // @@protoc_insertion_point(class_scope:test_2.usr_login)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr usrname_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr usrpasswd_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_msg_2eproto;
};
// -------------------------------------------------------------------

class usr_info PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:test_2.usr_info) */ {
 public:
  inline usr_info() : usr_info(nullptr) {}
  virtual ~usr_info();

  usr_info(const usr_info& from);
  usr_info(usr_info&& from) noexcept
    : usr_info() {
    *this = ::std::move(from);
  }

  inline usr_info& operator=(const usr_info& from) {
    CopyFrom(from);
    return *this;
  }
  inline usr_info& operator=(usr_info&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const usr_info& default_instance();

  static inline const usr_info* internal_default_instance() {
    return reinterpret_cast<const usr_info*>(
               &_usr_info_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(usr_info& a, usr_info& b) {
    a.Swap(&b);
  }
  inline void Swap(usr_info* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(usr_info* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline usr_info* New() const final {
    return CreateMaybeMessage<usr_info>(nullptr);
  }

  usr_info* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<usr_info>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const usr_info& from);
  void MergeFrom(const usr_info& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(usr_info* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "test_2.usr_info";
  }
  protected:
  explicit usr_info(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_msg_2eproto);
    return ::descriptor_table_msg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStudentIDFieldNumber = 2,
    kClassromeFieldNumber = 1,
  };
  // string studentID = 2;
  void clear_studentid();
  const std::string& studentid() const;
  void set_studentid(const std::string& value);
  void set_studentid(std::string&& value);
  void set_studentid(const char* value);
  void set_studentid(const char* value, size_t size);
  std::string* mutable_studentid();
  std::string* release_studentid();
  void set_allocated_studentid(std::string* studentid);
  private:
  const std::string& _internal_studentid() const;
  void _internal_set_studentid(const std::string& value);
  std::string* _internal_mutable_studentid();
  public:

  // int32 classrome = 1;
  void clear_classrome();
  ::PROTOBUF_NAMESPACE_ID::int32 classrome() const;
  void set_classrome(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_classrome() const;
  void _internal_set_classrome(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:test_2.usr_info)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr studentid_;
  ::PROTOBUF_NAMESPACE_ID::int32 classrome_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_msg_2eproto;
};
// -------------------------------------------------------------------

class student PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:test_2.student) */ {
 public:
  inline student() : student(nullptr) {}
  virtual ~student();

  student(const student& from);
  student(student&& from) noexcept
    : student() {
    *this = ::std::move(from);
  }

  inline student& operator=(const student& from) {
    CopyFrom(from);
    return *this;
  }
  inline student& operator=(student&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const student& default_instance();

  static inline const student* internal_default_instance() {
    return reinterpret_cast<const student*>(
               &_student_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(student& a, student& b) {
    a.Swap(&b);
  }
  inline void Swap(student* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(student* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline student* New() const final {
    return CreateMaybeMessage<student>(nullptr);
  }

  student* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<student>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const student& from);
  void MergeFrom(const student& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(student* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "test_2.student";
  }
  protected:
  explicit student(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_msg_2eproto);
    return ::descriptor_table_msg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kArrayFieldNumber = 4,
    kUsrLoginFieldNumber = 2,
    kUsrInfoFieldNumber = 3,
    kSTAMPFieldNumber = 1,
  };
  // repeated int32 array = 4;
  int array_size() const;
  private:
  int _internal_array_size() const;
  public:
  void clear_array();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_array(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_array() const;
  void _internal_add_array(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_array();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 array(int index) const;
  void set_array(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_array(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      array() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_array();

  // .test_2.usr_login usrLogin = 2;
  bool has_usrlogin() const;
  private:
  bool _internal_has_usrlogin() const;
  public:
  void clear_usrlogin();
  const ::test_2::usr_login& usrlogin() const;
  ::test_2::usr_login* release_usrlogin();
  ::test_2::usr_login* mutable_usrlogin();
  void set_allocated_usrlogin(::test_2::usr_login* usrlogin);
  private:
  const ::test_2::usr_login& _internal_usrlogin() const;
  ::test_2::usr_login* _internal_mutable_usrlogin();
  public:
  void unsafe_arena_set_allocated_usrlogin(
      ::test_2::usr_login* usrlogin);
  ::test_2::usr_login* unsafe_arena_release_usrlogin();

  // .test_2.usr_info usrInfo = 3;
  bool has_usrinfo() const;
  private:
  bool _internal_has_usrinfo() const;
  public:
  void clear_usrinfo();
  const ::test_2::usr_info& usrinfo() const;
  ::test_2::usr_info* release_usrinfo();
  ::test_2::usr_info* mutable_usrinfo();
  void set_allocated_usrinfo(::test_2::usr_info* usrinfo);
  private:
  const ::test_2::usr_info& _internal_usrinfo() const;
  ::test_2::usr_info* _internal_mutable_usrinfo();
  public:
  void unsafe_arena_set_allocated_usrinfo(
      ::test_2::usr_info* usrinfo);
  ::test_2::usr_info* unsafe_arena_release_usrinfo();

  // int32 STAMP = 1;
  void clear_stamp();
  ::PROTOBUF_NAMESPACE_ID::int32 stamp() const;
  void set_stamp(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_stamp() const;
  void _internal_set_stamp(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:test_2.student)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > array_;
  mutable std::atomic<int> _array_cached_byte_size_;
  ::test_2::usr_login* usrlogin_;
  ::test_2::usr_info* usrinfo_;
  ::PROTOBUF_NAMESPACE_ID::int32 stamp_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_msg_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// usr_login

// string usrname = 1;
inline void usr_login::clear_usrname() {
  usrname_.ClearToEmpty();
}
inline const std::string& usr_login::usrname() const {
  // @@protoc_insertion_point(field_get:test_2.usr_login.usrname)
  return _internal_usrname();
}
inline void usr_login::set_usrname(const std::string& value) {
  _internal_set_usrname(value);
  // @@protoc_insertion_point(field_set:test_2.usr_login.usrname)
}
inline std::string* usr_login::mutable_usrname() {
  // @@protoc_insertion_point(field_mutable:test_2.usr_login.usrname)
  return _internal_mutable_usrname();
}
inline const std::string& usr_login::_internal_usrname() const {
  return usrname_.Get();
}
inline void usr_login::_internal_set_usrname(const std::string& value) {
  
  usrname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void usr_login::set_usrname(std::string&& value) {
  
  usrname_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:test_2.usr_login.usrname)
}
inline void usr_login::set_usrname(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  usrname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:test_2.usr_login.usrname)
}
inline void usr_login::set_usrname(const char* value,
    size_t size) {
  
  usrname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:test_2.usr_login.usrname)
}
inline std::string* usr_login::_internal_mutable_usrname() {
  
  return usrname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* usr_login::release_usrname() {
  // @@protoc_insertion_point(field_release:test_2.usr_login.usrname)
  return usrname_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void usr_login::set_allocated_usrname(std::string* usrname) {
  if (usrname != nullptr) {
    
  } else {
    
  }
  usrname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), usrname,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:test_2.usr_login.usrname)
}

// string usrpasswd = 2;
inline void usr_login::clear_usrpasswd() {
  usrpasswd_.ClearToEmpty();
}
inline const std::string& usr_login::usrpasswd() const {
  // @@protoc_insertion_point(field_get:test_2.usr_login.usrpasswd)
  return _internal_usrpasswd();
}
inline void usr_login::set_usrpasswd(const std::string& value) {
  _internal_set_usrpasswd(value);
  // @@protoc_insertion_point(field_set:test_2.usr_login.usrpasswd)
}
inline std::string* usr_login::mutable_usrpasswd() {
  // @@protoc_insertion_point(field_mutable:test_2.usr_login.usrpasswd)
  return _internal_mutable_usrpasswd();
}
inline const std::string& usr_login::_internal_usrpasswd() const {
  return usrpasswd_.Get();
}
inline void usr_login::_internal_set_usrpasswd(const std::string& value) {
  
  usrpasswd_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void usr_login::set_usrpasswd(std::string&& value) {
  
  usrpasswd_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:test_2.usr_login.usrpasswd)
}
inline void usr_login::set_usrpasswd(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  usrpasswd_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:test_2.usr_login.usrpasswd)
}
inline void usr_login::set_usrpasswd(const char* value,
    size_t size) {
  
  usrpasswd_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:test_2.usr_login.usrpasswd)
}
inline std::string* usr_login::_internal_mutable_usrpasswd() {
  
  return usrpasswd_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* usr_login::release_usrpasswd() {
  // @@protoc_insertion_point(field_release:test_2.usr_login.usrpasswd)
  return usrpasswd_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void usr_login::set_allocated_usrpasswd(std::string* usrpasswd) {
  if (usrpasswd != nullptr) {
    
  } else {
    
  }
  usrpasswd_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), usrpasswd,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:test_2.usr_login.usrpasswd)
}

// -------------------------------------------------------------------

// usr_info

// int32 classrome = 1;
inline void usr_info::clear_classrome() {
  classrome_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 usr_info::_internal_classrome() const {
  return classrome_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 usr_info::classrome() const {
  // @@protoc_insertion_point(field_get:test_2.usr_info.classrome)
  return _internal_classrome();
}
inline void usr_info::_internal_set_classrome(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  classrome_ = value;
}
inline void usr_info::set_classrome(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_classrome(value);
  // @@protoc_insertion_point(field_set:test_2.usr_info.classrome)
}

// string studentID = 2;
inline void usr_info::clear_studentid() {
  studentid_.ClearToEmpty();
}
inline const std::string& usr_info::studentid() const {
  // @@protoc_insertion_point(field_get:test_2.usr_info.studentID)
  return _internal_studentid();
}
inline void usr_info::set_studentid(const std::string& value) {
  _internal_set_studentid(value);
  // @@protoc_insertion_point(field_set:test_2.usr_info.studentID)
}
inline std::string* usr_info::mutable_studentid() {
  // @@protoc_insertion_point(field_mutable:test_2.usr_info.studentID)
  return _internal_mutable_studentid();
}
inline const std::string& usr_info::_internal_studentid() const {
  return studentid_.Get();
}
inline void usr_info::_internal_set_studentid(const std::string& value) {
  
  studentid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void usr_info::set_studentid(std::string&& value) {
  
  studentid_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:test_2.usr_info.studentID)
}
inline void usr_info::set_studentid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  studentid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:test_2.usr_info.studentID)
}
inline void usr_info::set_studentid(const char* value,
    size_t size) {
  
  studentid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:test_2.usr_info.studentID)
}
inline std::string* usr_info::_internal_mutable_studentid() {
  
  return studentid_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* usr_info::release_studentid() {
  // @@protoc_insertion_point(field_release:test_2.usr_info.studentID)
  return studentid_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void usr_info::set_allocated_studentid(std::string* studentid) {
  if (studentid != nullptr) {
    
  } else {
    
  }
  studentid_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), studentid,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:test_2.usr_info.studentID)
}

// -------------------------------------------------------------------

// student

// int32 STAMP = 1;
inline void student::clear_stamp() {
  stamp_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 student::_internal_stamp() const {
  return stamp_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 student::stamp() const {
  // @@protoc_insertion_point(field_get:test_2.student.STAMP)
  return _internal_stamp();
}
inline void student::_internal_set_stamp(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  stamp_ = value;
}
inline void student::set_stamp(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_stamp(value);
  // @@protoc_insertion_point(field_set:test_2.student.STAMP)
}

// .test_2.usr_login usrLogin = 2;
inline bool student::_internal_has_usrlogin() const {
  return this != internal_default_instance() && usrlogin_ != nullptr;
}
inline bool student::has_usrlogin() const {
  return _internal_has_usrlogin();
}
inline void student::clear_usrlogin() {
  if (GetArena() == nullptr && usrlogin_ != nullptr) {
    delete usrlogin_;
  }
  usrlogin_ = nullptr;
}
inline const ::test_2::usr_login& student::_internal_usrlogin() const {
  const ::test_2::usr_login* p = usrlogin_;
  return p != nullptr ? *p : reinterpret_cast<const ::test_2::usr_login&>(
      ::test_2::_usr_login_default_instance_);
}
inline const ::test_2::usr_login& student::usrlogin() const {
  // @@protoc_insertion_point(field_get:test_2.student.usrLogin)
  return _internal_usrlogin();
}
inline void student::unsafe_arena_set_allocated_usrlogin(
    ::test_2::usr_login* usrlogin) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(usrlogin_);
  }
  usrlogin_ = usrlogin;
  if (usrlogin) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:test_2.student.usrLogin)
}
inline ::test_2::usr_login* student::release_usrlogin() {
  
  ::test_2::usr_login* temp = usrlogin_;
  usrlogin_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::test_2::usr_login* student::unsafe_arena_release_usrlogin() {
  // @@protoc_insertion_point(field_release:test_2.student.usrLogin)
  
  ::test_2::usr_login* temp = usrlogin_;
  usrlogin_ = nullptr;
  return temp;
}
inline ::test_2::usr_login* student::_internal_mutable_usrlogin() {
  
  if (usrlogin_ == nullptr) {
    auto* p = CreateMaybeMessage<::test_2::usr_login>(GetArena());
    usrlogin_ = p;
  }
  return usrlogin_;
}
inline ::test_2::usr_login* student::mutable_usrlogin() {
  // @@protoc_insertion_point(field_mutable:test_2.student.usrLogin)
  return _internal_mutable_usrlogin();
}
inline void student::set_allocated_usrlogin(::test_2::usr_login* usrlogin) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete usrlogin_;
  }
  if (usrlogin) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(usrlogin);
    if (message_arena != submessage_arena) {
      usrlogin = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, usrlogin, submessage_arena);
    }
    
  } else {
    
  }
  usrlogin_ = usrlogin;
  // @@protoc_insertion_point(field_set_allocated:test_2.student.usrLogin)
}

// .test_2.usr_info usrInfo = 3;
inline bool student::_internal_has_usrinfo() const {
  return this != internal_default_instance() && usrinfo_ != nullptr;
}
inline bool student::has_usrinfo() const {
  return _internal_has_usrinfo();
}
inline void student::clear_usrinfo() {
  if (GetArena() == nullptr && usrinfo_ != nullptr) {
    delete usrinfo_;
  }
  usrinfo_ = nullptr;
}
inline const ::test_2::usr_info& student::_internal_usrinfo() const {
  const ::test_2::usr_info* p = usrinfo_;
  return p != nullptr ? *p : reinterpret_cast<const ::test_2::usr_info&>(
      ::test_2::_usr_info_default_instance_);
}
inline const ::test_2::usr_info& student::usrinfo() const {
  // @@protoc_insertion_point(field_get:test_2.student.usrInfo)
  return _internal_usrinfo();
}
inline void student::unsafe_arena_set_allocated_usrinfo(
    ::test_2::usr_info* usrinfo) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(usrinfo_);
  }
  usrinfo_ = usrinfo;
  if (usrinfo) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:test_2.student.usrInfo)
}
inline ::test_2::usr_info* student::release_usrinfo() {
  
  ::test_2::usr_info* temp = usrinfo_;
  usrinfo_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::test_2::usr_info* student::unsafe_arena_release_usrinfo() {
  // @@protoc_insertion_point(field_release:test_2.student.usrInfo)
  
  ::test_2::usr_info* temp = usrinfo_;
  usrinfo_ = nullptr;
  return temp;
}
inline ::test_2::usr_info* student::_internal_mutable_usrinfo() {
  
  if (usrinfo_ == nullptr) {
    auto* p = CreateMaybeMessage<::test_2::usr_info>(GetArena());
    usrinfo_ = p;
  }
  return usrinfo_;
}
inline ::test_2::usr_info* student::mutable_usrinfo() {
  // @@protoc_insertion_point(field_mutable:test_2.student.usrInfo)
  return _internal_mutable_usrinfo();
}
inline void student::set_allocated_usrinfo(::test_2::usr_info* usrinfo) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete usrinfo_;
  }
  if (usrinfo) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(usrinfo);
    if (message_arena != submessage_arena) {
      usrinfo = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, usrinfo, submessage_arena);
    }
    
  } else {
    
  }
  usrinfo_ = usrinfo;
  // @@protoc_insertion_point(field_set_allocated:test_2.student.usrInfo)
}

// repeated int32 array = 4;
inline int student::_internal_array_size() const {
  return array_.size();
}
inline int student::array_size() const {
  return _internal_array_size();
}
inline void student::clear_array() {
  array_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 student::_internal_array(int index) const {
  return array_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 student::array(int index) const {
  // @@protoc_insertion_point(field_get:test_2.student.array)
  return _internal_array(index);
}
inline void student::set_array(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  array_.Set(index, value);
  // @@protoc_insertion_point(field_set:test_2.student.array)
}
inline void student::_internal_add_array(::PROTOBUF_NAMESPACE_ID::int32 value) {
  array_.Add(value);
}
inline void student::add_array(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_array(value);
  // @@protoc_insertion_point(field_add:test_2.student.array)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
student::_internal_array() const {
  return array_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
student::array() const {
  // @@protoc_insertion_point(field_list:test_2.student.array)
  return _internal_array();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
student::_internal_mutable_array() {
  return &array_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
student::mutable_array() {
  // @@protoc_insertion_point(field_mutable_list:test_2.student.array)
  return _internal_mutable_array();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace test_2

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_msg_2eproto