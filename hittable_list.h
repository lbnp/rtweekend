#pragma once
#include "hittable.h"

class hittable_list : public hittable {
public:
    hittable_list() {}
    hittable_list(hittable** l, int n) : list(l), list_size(n) {}
    bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const override;
    hittable** list;
    int list_size;
};

bool hittable_list::hit(const ray& r, float tmin, float tmax, hit_record& rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    float closest_so_far = tmax;
    for (uint32_t i = 0; i < list_size; ++i) {
        if (list[i]->hit(r, tmin, closest_so_far, temp_rec)) {
            hit_anything = true;
            rec = temp_rec;
            closest_so_far = temp_rec.t;
        }
    }
    return hit_anything;
}