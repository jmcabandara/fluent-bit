/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2016 Treasure Data Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_URI_H
#define FLB_URI_H

#include <mk_core.h>

/* By default we allow a maximum of 8 URI patterns in our map */
#define FLB_URI_MAX       8

struct flb_uri_field {
    size_t length;
    char *value;
    struct mk_list _head;
};

struct flb_uri {
    uint8_t count;                 /* Number of entries of the list */
    struct mk_list list;           /* List head for uri patterns    */
    struct flb_uri_field *map;     /* Map / O(1) lookup by position */
};

struct flb_uri_field *flb_uri_get(struct flb_uri *uri, int pos);
struct flb_uri *flb_uri_create(char *full_uri);
void flb_uri_destroy(struct flb_uri *uri);
void flb_uri_dump(struct flb_uri *uri);

#endif
