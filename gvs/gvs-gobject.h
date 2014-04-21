/* gvs-gobject.h: Default serialization of GObjects
 *
 * Copyright (c) 2014 Tristan Brindle <t.c.brindle@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GVS_GOBJECT_H__
#define __GVS_GOBJECT_H__

#if !defined (__GVS_INSIDE__)
#error "Only <gom.h> can be included directly."
#endif

#include <glib-object.h>

G_BEGIN_DECLS

typedef GVariant *(*GvsPropertySerializeFunc)  (const GValue *value);

typedef void      (*GvsPropertyDeserializeFunc) (GVariant *variant,
                                                 GValue *value);

void         gvs_register_property_serialize_func(GParamSpec *pspec,
                                                  GvsPropertySerializeFunc serialize);

void         gvs_register_property_serialize_func_full(GParamSpec *pspec,
                                                       GvsPropertySerializeFunc serialize,
                                                       gpointer user_data,
                                                       GDestroyNotify destroy_notify);

void         gvs_register_property_deserialize_func(GParamSpec *pspec,
                                                    GvsPropertyDeserializeFunc deserialize);

void         gvs_register_property_deserialize_func_full(GParamSpec *pspec,
                                                         GvsPropertyDeserializeFunc deserialize,
                                                         gpointer user_data,
                                                         GDestroyNotify destroy_notify);

GVariant    *gvs_gobject_serialize_property_by_pspec(GParamSpec *pspec,
                                                     GValue     *value);

void         gvs_gobject_deserialize_property(GObject *object,
                                              const char *property_name,
                                              GVariant *variant);

GVariant    *gvs_gobject_serialize(GObject *object);

void         gvs_gobject_deserialize(GObject *object,
                                     GVariant *variant);

gpointer     gvs_gobject_new_deserialize(GVariant *variant);

G_END_DECLS

#endif
