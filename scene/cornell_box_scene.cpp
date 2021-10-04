//
// Created by Артем on 02.10.2021.
//

#include "cornell_box_scene.hpp"
#include "materials/material_lambertian.hpp"
#include "materials/material_metal.hpp"
#include "materials/material_lambertian_light.hpp"
#include "build_cube.hpp"
#include "build_rect.hpp"

Scene* cornell_box_scene() {
    Scene* scene = new Scene();

    Material *m_white = new MaterialLambertian({1, 1, 1});
    Material *m_red   = new MaterialLambertian({1, 0, 0});
    Material *m_green = new MaterialLambertian({0, 1, 0});
    Material *m_light = new MaterialLambertianLight({1, 1, 1}, {1, 1, 1});

    Material *m_mirror = new MaterialMetal({1, 1, 0.5}, 0.05);

    float lamp_size = 1.6;
    float box_size = 10;

    build_cube(scene->get_root_hittable(), Matrix4f::scale_matrix(box_size, box_size, box_size), (Material*[6]){
        m_white, nullptr,
        m_red, m_green,
        m_white, m_white
    });

    build_rect(scene->get_root_hittable(), m_light, {0, 0, box_size / 2 - Vec3f::epsilon}, {lamp_size, lamp_size, 0}, {lamp_size, -lamp_size, 0});

    build_cube(scene->get_root_hittable(),
               Matrix4f::scale_matrix(box_size * 0.2, box_size * 0.2, box_size * 0.75) *
               Matrix4f::rotation_z_matrix(M_PI * 0.3) *
               Matrix4f::translation_matrix(box_size * 0.2, -box_size * 0.4, -box_size * 0.25 * 0.5)
    , m_white);

    build_cube(scene->get_root_hittable(),
               Matrix4f::scale_matrix(box_size * 0.2, box_size * 0.2, box_size * 0.25) *
               Matrix4f::rotation_z_matrix(M_PI * -0.3) *
               Matrix4f::translation_matrix(-box_size * 0.2, box_size * 0.3, -box_size * 0.75 * 0.5)
    , m_white);

    return scene;
}
