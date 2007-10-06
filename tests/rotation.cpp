// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
// Copyright 2006  Braden McDaniel
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

# define BOOST_TEST_MAIN
# define BOOST_TEST_MODULE rotation

# include <sstream>
# include <boost/test/unit_test.hpp>
# include <openvrml/basetypes.h>

using namespace std;
using namespace openvrml;

BOOST_AUTO_TEST_CASE(stream_extraction_fail_on_nonnormalized_axis)
{
    string rotation_str = "2.0 2.0 0.0 0.0";
    istringstream in(rotation_str);
    rotation r;
    in >> r;
    BOOST_REQUIRE(in.fail());
}
