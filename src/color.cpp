#include <nanogui/color.h>
#include <nanogui/object.h>

#include <map>
#include <string>

#define __ASSIGN_COLOR(a,b) const Color Color::a = Color(b);
#define __ADD_COLOR(a) _colors[ StrNameFnHash(#a) ] = &Color::a;

NAMESPACE_BEGIN(nanogui)

namespace 
{
static std::map<unsigned int, const Color*> _colors;

void createColors()
{
__ADD_COLOR( transparent    )
__ADD_COLOR( red            )
__ADD_COLOR( caesarRed      )
__ADD_COLOR( blue           )
__ADD_COLOR( green          )
__ADD_COLOR( show           )
__ADD_COLOR( ghost          )
__ADD_COLOR( whitesmoke     )
__ADD_COLOR( floralwhite    )
__ADD_COLOR( oldlace        )
__ADD_COLOR( linen          )
__ADD_COLOR( antiqueWhite   )
__ADD_COLOR( papayaWhip     )
__ADD_COLOR( blanchedAlmond )
__ADD_COLOR( bisque         )
__ADD_COLOR( peachPuff      )
__ADD_COLOR( navajoWhite    )
__ADD_COLOR( moccasin       )
__ADD_COLOR( cornsilk       )
__ADD_COLOR( ivory          )
__ADD_COLOR( lemonChiffon   )
__ADD_COLOR( seashell       )
__ADD_COLOR( honeydew       )
__ADD_COLOR( mintCream      )
__ADD_COLOR( azure          )
__ADD_COLOR( aliceBlue      )
__ADD_COLOR( lavender       )
__ADD_COLOR( lavenderBlush  )
__ADD_COLOR( mistyRose      )
__ADD_COLOR( white          )
__ADD_COLOR( black          )
__ADD_COLOR( darkSlateGray  )
__ADD_COLOR( dimGrey        )
__ADD_COLOR( slateGrey      )
__ADD_COLOR( lightSlateGray )
__ADD_COLOR( grey           )
__ADD_COLOR( lightGray      )
__ADD_COLOR( midnightBlue    )
__ADD_COLOR( navyBlue        )
__ADD_COLOR( cornflowerBlue  )
__ADD_COLOR( darkSlateBlue	 )
__ADD_COLOR( slateBlue       )
__ADD_COLOR( mediumSlateBlue )
__ADD_COLOR( lightSlateBlue	 )
__ADD_COLOR( mediumBlue	     )
__ADD_COLOR( royalBlue	     )
__ADD_COLOR( skyBlue         )
__ADD_COLOR( paleTurquoise	 )
__ADD_COLOR( cyan            )
__ADD_COLOR( mediumAquamarine)
__ADD_COLOR( darkGreen       )
__ADD_COLOR( darkSeaGreen    )
__ADD_COLOR( paleGreen	     )
__ADD_COLOR( limeGreen	     )
__ADD_COLOR( darkKhaki	     )
__ADD_COLOR( paleGoldenrod	 )
__ADD_COLOR( yellow          )
__ADD_COLOR( gold            )
__ADD_COLOR( rosyBrown	     )
__ADD_COLOR( indianRed	     )
__ADD_COLOR( sienna          )
__ADD_COLOR( peru            )
__ADD_COLOR( wheat           )
__ADD_COLOR( sandyBrown      )
__ADD_COLOR( tan             )
__ADD_COLOR( chocolate	     )
__ADD_COLOR( firebrick	     )
__ADD_COLOR( brown	         )
__ADD_COLOR( salmon	         )
__ADD_COLOR( orange	         )
__ADD_COLOR( darkOrange      )
__ADD_COLOR( coral	         )
__ADD_COLOR( tomato	         )
__ADD_COLOR( orangeRed	     )
__ADD_COLOR( hotPink	       )
__ADD_COLOR( deepPink	       )
__ADD_COLOR( pink            )
__ADD_COLOR( maroon          )
__ADD_COLOR( magenta         )
__ADD_COLOR( violet	         )
__ADD_COLOR( orchid	         )
__ADD_COLOR( purple	         )
__ADD_COLOR( snow            )
__ADD_COLOR( dodgerBlue     )
__ADD_COLOR( steelBlue      )
__ADD_COLOR( slateGray      )
__ADD_COLOR( aquamarine     )
__ADD_COLOR( seaGreen       )
__ADD_COLOR( springGreen    )
__ADD_COLOR( chartreuse     )
__ADD_COLOR( plum           )
__ADD_COLOR( thistle        )
__ADD_COLOR( darkGrey       )
__ADD_COLOR( heavyDarkGrey  )
__ADD_COLOR( ligthDarkGrey  )
}

} // end namespace

const Color& Color::find(const std::string& name)
{
  if (_colors.empty())
    createColors();

  auto it = _colors.find(StrNameFnHash(name.c_str()));
  if( it != _colors.end() )
    return *it->second;
  else if (name.size()>2&&name[0]=='0'&&name[1]=='x')
  {
    int value = std::stoul(name.substr(2), nullptr,16);
    unsigned int hash = StrNameFnHash(name.c_str());
    _colors[hash] = (new Color(value));
    return *_colors[hash];
  }

  return Color::transparent;
}

__ASSIGN_COLOR( transparent,    0x00000001 )
__ASSIGN_COLOR( red,            0xff0000ff )
__ASSIGN_COLOR( caesarRed,      0xA00000ff )
__ASSIGN_COLOR( blue,           0x0000ffff )
__ASSIGN_COLOR( green,          0x00ff00ff )
__ASSIGN_COLOR( show,           0xfffafaff )
__ASSIGN_COLOR( ghost,          0xF8F8FFff )
__ASSIGN_COLOR( whitesmoke,     0xF5F5F5ff )
__ASSIGN_COLOR( floralwhite,    0xFFFAF0ff )
__ASSIGN_COLOR( oldlace,        0xFDF5E6ff )
__ASSIGN_COLOR( linen,          0xFAF0E6ff )
__ASSIGN_COLOR( antiqueWhite,   0xFAEBD7ff )
__ASSIGN_COLOR( papayaWhip,     0xFFEFD5ff )
__ASSIGN_COLOR( blanchedAlmond, 0xFFEBCDff )
__ASSIGN_COLOR( bisque,         0xFFE4C4ff )
__ASSIGN_COLOR( peachPuff,      0xFFDAB9ff )
__ASSIGN_COLOR( navajoWhite,    0xFFDEADff )
__ASSIGN_COLOR( moccasin,       0xFFE4B5ff )
__ASSIGN_COLOR( cornsilk,       0xFFF8DCff )
__ASSIGN_COLOR( ivory,          0xFFFFF0ff )
__ASSIGN_COLOR( lemonChiffon,   0xFFFACDff )
__ASSIGN_COLOR( seashell,       0xFFF5EEff )
__ASSIGN_COLOR( honeydew,       0xF0FFF0ff )
__ASSIGN_COLOR( mintCream,      0xF5FFFAff )
__ASSIGN_COLOR( azure,          0xF0FFFFff )
__ASSIGN_COLOR( aliceBlue,      0xF0F8FFff )
__ASSIGN_COLOR( lavender,       0xE6E6FAff )
__ASSIGN_COLOR( lavenderBlush,  0xFFF0F5ff )
__ASSIGN_COLOR( mistyRose,      0xFFE4E1ff )
__ASSIGN_COLOR( white,          0xFFFFFFff )
__ASSIGN_COLOR( black,          0x000000ff )
__ASSIGN_COLOR( darkSlateGray,  0x2F4F4Fff )
__ASSIGN_COLOR( dimGrey,        0x696969ff )
__ASSIGN_COLOR( slateGrey,      0x708090ff )
__ASSIGN_COLOR( lightSlateGray,	0x778899ff )
__ASSIGN_COLOR( grey,           0xBEBEBEff )
__ASSIGN_COLOR( lightGray,      0xD3D3D3ff )
__ASSIGN_COLOR( midnightBlue,   0x191970ff )
__ASSIGN_COLOR( navyBlue,       0x000080ff )
__ASSIGN_COLOR( cornflowerBlue,	0x6495EDff )
__ASSIGN_COLOR( darkSlateBlue,	0x483D8Bff )
__ASSIGN_COLOR( slateBlue,      0x6A5ACDff )
__ASSIGN_COLOR( mediumSlateBlue,0x7B68EEff )
__ASSIGN_COLOR( lightSlateBlue,	0x8470FFff )
__ASSIGN_COLOR( mediumBlue,	    0x0000CDff )
__ASSIGN_COLOR( royalBlue,	    0x4169E1ff )
__ASSIGN_COLOR( skyBlue,        0x87CEEBff )
__ASSIGN_COLOR( paleTurquoise,	0xAFEEEEff )
__ASSIGN_COLOR( cyan,           0x00FFFFff )
__ASSIGN_COLOR( mediumAquamarine, 0x66CDAAff)
__ASSIGN_COLOR( darkGreen,      0x006400ff )
__ASSIGN_COLOR( darkSeaGreen,   0x8FBC8Fff )
__ASSIGN_COLOR( paleGreen,	    0x98FB98ff )
__ASSIGN_COLOR( limeGreen,	    0x32CD32ff )
__ASSIGN_COLOR( darkKhaki,	    0xBDB76Bff )
__ASSIGN_COLOR( paleGoldenrod,	0xEEE8AAff )
__ASSIGN_COLOR( yellow,         0xFFFF00ff )
__ASSIGN_COLOR( gold,           0xFFD700ff )
__ASSIGN_COLOR( rosyBrown,	    0xBC8F8Fff )
__ASSIGN_COLOR( indianRed,	    0xCD5C5Cff )
__ASSIGN_COLOR( sienna,         0xA0522Dff )
__ASSIGN_COLOR( peru,           0xCD853Fff )
__ASSIGN_COLOR( wheat,          0xF5DEB3ff )
__ASSIGN_COLOR( sandyBrown,     0xF4A460ff )
__ASSIGN_COLOR( tan,            0xD2B48Cff )
__ASSIGN_COLOR( chocolate,	    0xD2691Eff )
__ASSIGN_COLOR( firebrick,	    0xB22222ff )
__ASSIGN_COLOR( brown,	        0xA52A2Aff )
__ASSIGN_COLOR( salmon,	        0xFA8072ff )
__ASSIGN_COLOR( orange,	        0xFFA500ff )
__ASSIGN_COLOR( darkOrange,     0xFF8C00ff )
__ASSIGN_COLOR( coral,	        0xFF7F50ff )
__ASSIGN_COLOR( tomato,	        0xFF6347ff )
__ASSIGN_COLOR( orangeRed,	    0xFF4500ff )
__ASSIGN_COLOR( hotPink,	      0xFF69B4ff )
__ASSIGN_COLOR( deepPink,	      0xFF1493ff )
__ASSIGN_COLOR( pink,           0xFFC0CBff )
__ASSIGN_COLOR( maroon,         0xB03060ff )
__ASSIGN_COLOR( magenta,        0xFF00FFff )
__ASSIGN_COLOR( violet,	        0xEE82EEff )
__ASSIGN_COLOR( orchid,	        0xDA70D6ff )
__ASSIGN_COLOR( purple,	        0xA020F0ff )
__ASSIGN_COLOR( snow,           0xFFFAFAff )
__ASSIGN_COLOR( dodgerBlue,     0x1E90FFff )
__ASSIGN_COLOR( steelBlue,      0x63B8FFff )
__ASSIGN_COLOR( slateGray,      0xC6E2FFff )
__ASSIGN_COLOR( aquamarine,     0x7FFFD4ff )
__ASSIGN_COLOR( seaGreen,       0x54FF9Fff )
__ASSIGN_COLOR( springGreen,    0x00FF7Fff )
__ASSIGN_COLOR( chartreuse,     0x7FFF00ff )
__ASSIGN_COLOR( plum,           0xFFBBFFff )
__ASSIGN_COLOR( thistle,        0xFFE1FFff )
__ASSIGN_COLOR( darkGrey,       0x4a4a4aff )
__ASSIGN_COLOR( heavyDarkGrey,  0x262626ff )
__ASSIGN_COLOR( ligthDarkGrey,  0x4a4a4aff )


NAMESPACE_END(nanogui)