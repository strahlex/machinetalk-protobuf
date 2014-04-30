/****************************************************************************
**
** Copyright (C) 2014 Alexander Rössler
** License: LGPL version 2.1
**
** This file is part of QtQuickVcp.
**
** All rights reserved. This program and the accompanying materials
** are made available under the terms of the GNU Lesser General Public License
** (LGPL) version 2.1 which accompanies this distribution, and is available at
** http://www.gnu.org/licenses/lgpl-2.1.html
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** Lesser General Public License for more details.
**
** Contributors:
** Alexander Rössler @ The Cool Tool GmbH <mail DOT aroessler AT gmail DOT com>
**
****************************************************************************/
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: emcclass.proto

#ifndef PROTOBUF_emcclass_2eproto__INCLUDED
#define PROTOBUF_emcclass_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace pb {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_emcclass_2eproto();
void protobuf_AssignDesc_emcclass_2eproto();
void protobuf_ShutdownFile_emcclass_2eproto();

class PmCartesian;
class EmcPose;

// ===================================================================

class PmCartesian : public ::google::protobuf::Message {
 public:
  PmCartesian();
  virtual ~PmCartesian();

  PmCartesian(const PmCartesian& from);

  inline PmCartesian& operator=(const PmCartesian& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PmCartesian& default_instance();

  void Swap(PmCartesian* other);

  // implements Message ----------------------------------------------

  PmCartesian* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PmCartesian& from);
  void MergeFrom(const PmCartesian& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional double x = 10;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 10;
  inline double x() const;
  inline void set_x(double value);

  // optional double y = 20;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 20;
  inline double y() const;
  inline void set_y(double value);

  // optional double z = 30;
  inline bool has_z() const;
  inline void clear_z();
  static const int kZFieldNumber = 30;
  inline double z() const;
  inline void set_z(double value);

  // @@protoc_insertion_point(class_scope:pb.PmCartesian)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_z();
  inline void clear_has_z();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  double x_;
  double y_;
  double z_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_emcclass_2eproto();
  friend void protobuf_AssignDesc_emcclass_2eproto();
  friend void protobuf_ShutdownFile_emcclass_2eproto();

  void InitAsDefaultInstance();
  static PmCartesian* default_instance_;
};
// -------------------------------------------------------------------

class EmcPose : public ::google::protobuf::Message {
 public:
  EmcPose();
  virtual ~EmcPose();

  EmcPose(const EmcPose& from);

  inline EmcPose& operator=(const EmcPose& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EmcPose& default_instance();

  void Swap(EmcPose* other);

  // implements Message ----------------------------------------------

  EmcPose* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const EmcPose& from);
  void MergeFrom(const EmcPose& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .pb.PmCartesian tran = 10;
  inline bool has_tran() const;
  inline void clear_tran();
  static const int kTranFieldNumber = 10;
  inline const ::pb::PmCartesian& tran() const;
  inline ::pb::PmCartesian* mutable_tran();
  inline ::pb::PmCartesian* release_tran();
  inline void set_allocated_tran(::pb::PmCartesian* tran);

  // optional double a = 20;
  inline bool has_a() const;
  inline void clear_a();
  static const int kAFieldNumber = 20;
  inline double a() const;
  inline void set_a(double value);

  // optional double b = 30;
  inline bool has_b() const;
  inline void clear_b();
  static const int kBFieldNumber = 30;
  inline double b() const;
  inline void set_b(double value);

  // optional double c = 40;
  inline bool has_c() const;
  inline void clear_c();
  static const int kCFieldNumber = 40;
  inline double c() const;
  inline void set_c(double value);

  // optional double u = 50;
  inline bool has_u() const;
  inline void clear_u();
  static const int kUFieldNumber = 50;
  inline double u() const;
  inline void set_u(double value);

  // optional double v = 60;
  inline bool has_v() const;
  inline void clear_v();
  static const int kVFieldNumber = 60;
  inline double v() const;
  inline void set_v(double value);

  // optional double w = 70;
  inline bool has_w() const;
  inline void clear_w();
  static const int kWFieldNumber = 70;
  inline double w() const;
  inline void set_w(double value);

  // @@protoc_insertion_point(class_scope:pb.EmcPose)
 private:
  inline void set_has_tran();
  inline void clear_has_tran();
  inline void set_has_a();
  inline void clear_has_a();
  inline void set_has_b();
  inline void clear_has_b();
  inline void set_has_c();
  inline void clear_has_c();
  inline void set_has_u();
  inline void clear_has_u();
  inline void set_has_v();
  inline void clear_has_v();
  inline void set_has_w();
  inline void clear_has_w();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::pb::PmCartesian* tran_;
  double a_;
  double b_;
  double c_;
  double u_;
  double v_;
  double w_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_emcclass_2eproto();
  friend void protobuf_AssignDesc_emcclass_2eproto();
  friend void protobuf_ShutdownFile_emcclass_2eproto();

  void InitAsDefaultInstance();
  static EmcPose* default_instance_;
};
// ===================================================================


// ===================================================================

// PmCartesian

// optional double x = 10;
inline bool PmCartesian::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PmCartesian::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PmCartesian::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PmCartesian::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline double PmCartesian::x() const {
  return x_;
}
inline void PmCartesian::set_x(double value) {
  set_has_x();
  x_ = value;
}

// optional double y = 20;
inline bool PmCartesian::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PmCartesian::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PmCartesian::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PmCartesian::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline double PmCartesian::y() const {
  return y_;
}
inline void PmCartesian::set_y(double value) {
  set_has_y();
  y_ = value;
}

// optional double z = 30;
inline bool PmCartesian::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PmCartesian::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PmCartesian::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PmCartesian::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline double PmCartesian::z() const {
  return z_;
}
inline void PmCartesian::set_z(double value) {
  set_has_z();
  z_ = value;
}

// -------------------------------------------------------------------

// EmcPose

// required .pb.PmCartesian tran = 10;
inline bool EmcPose::has_tran() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void EmcPose::set_has_tran() {
  _has_bits_[0] |= 0x00000001u;
}
inline void EmcPose::clear_has_tran() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void EmcPose::clear_tran() {
  if (tran_ != NULL) tran_->::pb::PmCartesian::Clear();
  clear_has_tran();
}
inline const ::pb::PmCartesian& EmcPose::tran() const {
  return tran_ != NULL ? *tran_ : *default_instance_->tran_;
}
inline ::pb::PmCartesian* EmcPose::mutable_tran() {
  set_has_tran();
  if (tran_ == NULL) tran_ = new ::pb::PmCartesian;
  return tran_;
}
inline ::pb::PmCartesian* EmcPose::release_tran() {
  clear_has_tran();
  ::pb::PmCartesian* temp = tran_;
  tran_ = NULL;
  return temp;
}
inline void EmcPose::set_allocated_tran(::pb::PmCartesian* tran) {
  delete tran_;
  tran_ = tran;
  if (tran) {
    set_has_tran();
  } else {
    clear_has_tran();
  }
}

// optional double a = 20;
inline bool EmcPose::has_a() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void EmcPose::set_has_a() {
  _has_bits_[0] |= 0x00000002u;
}
inline void EmcPose::clear_has_a() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void EmcPose::clear_a() {
  a_ = 0;
  clear_has_a();
}
inline double EmcPose::a() const {
  return a_;
}
inline void EmcPose::set_a(double value) {
  set_has_a();
  a_ = value;
}

// optional double b = 30;
inline bool EmcPose::has_b() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void EmcPose::set_has_b() {
  _has_bits_[0] |= 0x00000004u;
}
inline void EmcPose::clear_has_b() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void EmcPose::clear_b() {
  b_ = 0;
  clear_has_b();
}
inline double EmcPose::b() const {
  return b_;
}
inline void EmcPose::set_b(double value) {
  set_has_b();
  b_ = value;
}

// optional double c = 40;
inline bool EmcPose::has_c() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void EmcPose::set_has_c() {
  _has_bits_[0] |= 0x00000008u;
}
inline void EmcPose::clear_has_c() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void EmcPose::clear_c() {
  c_ = 0;
  clear_has_c();
}
inline double EmcPose::c() const {
  return c_;
}
inline void EmcPose::set_c(double value) {
  set_has_c();
  c_ = value;
}

// optional double u = 50;
inline bool EmcPose::has_u() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void EmcPose::set_has_u() {
  _has_bits_[0] |= 0x00000010u;
}
inline void EmcPose::clear_has_u() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void EmcPose::clear_u() {
  u_ = 0;
  clear_has_u();
}
inline double EmcPose::u() const {
  return u_;
}
inline void EmcPose::set_u(double value) {
  set_has_u();
  u_ = value;
}

// optional double v = 60;
inline bool EmcPose::has_v() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void EmcPose::set_has_v() {
  _has_bits_[0] |= 0x00000020u;
}
inline void EmcPose::clear_has_v() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void EmcPose::clear_v() {
  v_ = 0;
  clear_has_v();
}
inline double EmcPose::v() const {
  return v_;
}
inline void EmcPose::set_v(double value) {
  set_has_v();
  v_ = value;
}

// optional double w = 70;
inline bool EmcPose::has_w() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void EmcPose::set_has_w() {
  _has_bits_[0] |= 0x00000040u;
}
inline void EmcPose::clear_has_w() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void EmcPose::clear_w() {
  w_ = 0;
  clear_has_w();
}
inline double EmcPose::w() const {
  return w_;
}
inline void EmcPose::set_w(double value) {
  set_has_w();
  w_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_emcclass_2eproto__INCLUDED
