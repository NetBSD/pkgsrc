#
# Hack to fix up the Haskell package system bits.
#

# Remove nonexistent depends from wxcore.pkg. 
mv config/wxcore.pkg config/wxcore.pkg.orig
sed < config/wxcore.pkg.orig \
	-e "/depends/s/,lang//;/depends/s/,concurrent//" \
	> config/wxcore.pkg

# Create a temporary package database to import wxcore through while
# building wx. Otherwise it doesn't work.
echo '[]' > tmp-pkgdb
mkdir -p out/wx/imports
sed < config/wxcore.pkg \
	-e "s,.{wxhlibdir},@WRKSRC@/out/wx," \
	| ghc-pkg -f tmp-pkgdb register -


# And since we appear to *also* need to include from the output
# directory, make a version of it that doesn't show wxcore; otherwise
# ghc reads wxcore through the include path instead of its package
# system, and then fails.

mkdir -p out2/wx/imports/Graphics/UI/
ln -sf ../../../../../out/wx/imports/Graphics/UI/WX \
                     out2/wx/imports/Graphics/UI/WX
