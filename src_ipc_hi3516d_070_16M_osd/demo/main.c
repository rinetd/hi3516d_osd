#include <stdio.h>
#include <unistd.h>

#include "osd.h"

#define COLOR_RED       (0xFF0000)
#define COLOR_GREEN     (0x00FF00)
#define COLOR_BLUE      (0x0000FF)


int main(int argc, char *argv[])
{
    unsigned char au8Ver[32];
    OSD_ST stOsd;
    OSD_ST astOsdRead[10];
    OSD_ST astOsd[10] =
    {
        //polygon
        {
            .enType = OSD_POLYGON,
            .unData.stPolygon =
            {
                0, 1, 10,
                {{70, 10}, {100, 10}, {130, 40}, {160, 70}, {130, 100},
                    {100, 130}, {70, 130}, {40, 100}, {10, 70}, {40, 40}},
                COLOR_RED, 4,
                {0xFF000000 | COLOR_RED, 5, {{300, 0}, {300, 30}, {300, 60}, {300, 90}, {300, 120}}, {"line1~1", "line1_2", "line1_3", "line1_4", "line1_5"}}
            }
        },
        {
            OSD_POLYGON,
            .unData.stPolygon =
            {
                1, 1, 10,
                {{270, 10}, {300, 10}, {330, 40}, {360, 70}, {330, 100},
                    {300, 130}, {270, 130}, {240, 100}, {210, 70}, {240, 40}},
                COLOR_GREEN, 4,
                {0xFF000000 | COLOR_GREEN, 1, {{1000, 600}}, {"1 2 3 4"}}
            }
        },
        {
            OSD_POLYGON,
            .unData.stPolygon =
            {
                2, 0, 10,
                {{0, 0}},
                COLOR_BLUE, 4,
                {COLOR_BLUE, 0, {{0, 0}}, {"line1"}}
            }
        },
        {
            OSD_POLYGON,
            .unData.stPolygon =
            {
                3, 0, 10,
                {{0, 0}},
                COLOR_RED, 4,
                {COLOR_RED, 0, {{0, 0}}, {"line1"}}
            }
        },
        {
            OSD_POLYGON,
            .unData.stPolygon =
            {
                4, 0, 10,
                {{0, 0}},
                COLOR_RED, 4,
                {COLOR_RED, 0, {{0, 0}}, {"line1"}}
            }
        },

        // hotspot
        {
            OSD_HOTSPOT,
            .unData.stHotspot =
            {
                5, 1, 8,
                {{70, 40}, {70, 70}, {70, 100}, {40, 70},
                 {100, 40}, {100, 70}, {100, 100}, {130, 70}},
                COLOR_RED,
                {0xFF000000 | COLOR_RED, 1, {{500, 30}}, {"һ����abc"}}
            }
        },
        {
            OSD_HOTSPOT,
            .unData.stHotspot =
            {
                6, 1, 8,
                {{270, 40}, {270, 70}, {270, 100}, {240, 70},
                 {300, 40}, {300, 70}, {300, 100}, {330, 70}},
                COLOR_GREEN,
                {0xFF000000 | COLOR_GREEN, 1, {{1000, 800}}, {"�¶ȱ���: 100"}}
            }
        },
        {
            OSD_HOTSPOT,
            .unData.stHotspot =
            {
                7, 0, 8,
                {{0, 0}},
                COLOR_BLUE,
                {COLOR_BLUE, 0, {{0, 0}}, {"line1"}}
            }
        },
        {
            OSD_HOTSPOT,
            .unData.stHotspot =
            {
                8, 0, 8,
                {{0, 0}},
                COLOR_RED,
                {COLOR_RED, 0, {{0, 0}}, {"line1"}}
            }
        },
        {
            OSD_HOTSPOT,
            .unData.stHotspot =
            {
                9, 0, 8,
                {{0, 0}},
                COLOR_RED,
                {COLOR_RED, 0, {{0, 0}}, {"line1"}}
            }
        },
    };

    OSD_GetBuildVersion(au8Ver);
    OSD_Start(NULL);

    OSD_GetAll(astOsdRead);

    unsigned int u32Id;
    OSD_Set(&astOsd[0]);

    u32Id = 0;
    stOsd.enType = OSD_POLYGON;
    stOsd.unData.stPolygon.u32Id = u32Id;
    OSD_Get(&stOsd);
    OSD_Dump(&stOsd);

    OSD_Set(&astOsd[1]);

    u32Id = 1;
    stOsd.enType = OSD_POLYGON;
    stOsd.unData.stPolygon.u32Id = u32Id;
    OSD_Get(&stOsd);
    OSD_Dump(&stOsd);

    OSD_Set(&astOsd[0 + 5]);

    u32Id = 0 + 5;
    stOsd.enType = OSD_HOTSPOT;
    stOsd.unData.stHotspot.u32Id = u32Id;
    OSD_Get(&stOsd);
    OSD_Dump(&stOsd);

    OSD_Set(&astOsd[1 + 5]);

    u32Id = 1 + 5;
    stOsd.enType = OSD_HOTSPOT;
    stOsd.unData.stHotspot.u32Id = u32Id;
    OSD_Get(&stOsd);
    OSD_Dump(&stOsd);

    pause();
    OSD_Stop(NULL);

    return 0;
}
