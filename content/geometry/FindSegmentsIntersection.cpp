/**
* Author: Indy256
* Description: desc
*/
#include <utility>



typedef pair<int, int> pii;

int cross(int ax, int ay, int bx, int by, int cx, int cy) {
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

int cross(pii a, pii b, pii c) {
    return cross(a.first, a.second, b.first, b.second, c.first, c.second);
}

struct segment {
    pii a, b;
    int id;

    segment(pii a, pii b, int id) : a(std::move(a)), b(std::move(b)), id(id) {}

    bool operator<(const segment &o) const {
        if (a.first < o.a.first) {
            int s = cross(a, b, o.a);
            return (s > 0 || (s == 0 && a.second < o.a.second));
        } else if (a.first > o.a.first) {
            int s = cross(o.a, o.b, a);
            return (s < 0 || (s == 0 && a.second < o.a.second));
        }
        return a.second < o.a.second;
    }
};

struct event {
    pii p;
    int id;
    int type;

    event(pii p, int id, int type) : p(std::move(p)), id(id), type(type) {}

    bool operator<(const event &o) const {
        return p.first < o.p.first ||
               (p.first == o.p.first && (type > o.type || (type == o.type && p.second < o.p.second)));
    }
};

bool intersect(segment s1, segment s2) {
    int x1 = s1.a.first, y1 = s1.a.second, x2 = s1.b.first, y2 = s1.b.second;
    int x3 = s2.a.first, y3 = s2.a.second, x4 = s2.b.first, y4 = s2.b.second;
    if (max(x1, x2) < min(x3, x4) || max(x3, x4) < min(x1, x2) || max(y1, y2) < min(y3, y4) ||
        max(y3, y4) < min(y1, y2)) {
        return false;
    }
    int z1 = (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
    int z2 = (x4 - x1) * (y2 - y1) - (y4 - y1) * (x2 - x1);
    if ((z1 < 0 && z2 < 0) || (z1 > 0 && z2 > 0)) {
        return false;
    }
    int z3 = (x1 - x3) * (y4 - y3) - (y1 - y3) * (x4 - x3);
    int z4 = (x2 - x3) * (y4 - y3) - (y2 - y3) * (x4 - x3);
    if ((z3 < 0 && z4 < 0) || (z3 > 0 && z4 > 0)) {
        return false;
    }
    return true;
}

pii findIntersection(vector<segment> s) {
    int n = s.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        if (s[i].a > s[i].b)
            swap(s[i].a, s[i].b);
        e.emplace_back(s[i].a, i, 1);
        e.emplace_back(s[i].b, i, -1);
    }
    sort(e.begin(), e.end());

    set<segment> q;

    for (int i = 0; i < n * 2; ++i) {
        int id = e[i].id;
        if (e[i].type == 1) {
            auto it = q.lower_bound(s[id]);
            if (it != q.end() && intersect(*it, s[id]))
                return {it->id, s[id].id};
            if (it != q.begin() && intersect(*--it, s[id]))
                return {it->id, s[id].id};
            q.insert(s[id]);
        } else {
            auto it = q.lower_bound(s[id]), next = it, prev = it;
            if (it != q.begin() && it != --q.end()) {
                ++next, --prev;
                if (intersect(*next, *prev))
                    return {next->id, prev->id};
            }
            q.erase(it);
        }
    }
    return {-1, -1};
}

// usage example
int main() {}