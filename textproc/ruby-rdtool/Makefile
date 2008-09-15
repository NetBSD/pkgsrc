# $NetBSD: Makefile,v 1.28 2008/09/15 08:34:44 taca Exp $

DISTNAME=	rdtool-0.6.22
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/33346/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rdtool/
COMMENT=	RD (Ruby Document) converter to HTML/man/etc

PKG_DESTDIR_SUPPORT=	user-destdir

# Since rd2 commands depends its name and it can't rename, we cannot
# install multiple ruby??-rd2 package (unless supported by pkgview.
CONFLICTS+=	ruby[1-9][0-9]-rdtool-*

USE_RUBY_SETUP=	yes
REPLACE_RUBY=	bin/rd2 bin/rdswap

CONFIGURE_ARGS+= --siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
		--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
		--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

CONF_FILES+=	${PREFIX}/${RUBY_VENDORLIB}/rd/dot.rd2rc \
		${PKG_SYSCONFDIR}/dot.rd2rc

INSTALLATION_DIRS=	${RUBY_DOC}/rd ${RUBY_EG}/rd

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	bin/rd2
SUBST_SED.path=		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|"
SUBST_MESSAGE.path=	Fixing PKG_SYSCONFDIR paths.

DOCS_RD=	README.rd README.rd.ja doc/rd-draft.rd doc/rd-draft.rd.ja
DOCS=		${DOCS_RD} ${DOCS_RD:S/.rd/.html/}

pre-configure:
	cd ${WRKSRC}/bin; ${MV} rdswap.rb rdswap; ${CHMOD} ${BINMODE} rdswap

post-build:
.for f in ${DOCS_RD}
	cd ${WRKSRC}; ${RUBY} -I./lib bin/rd2 -r lib/rd/rd2html-lib.rb ${f} \
		> ${f:S/.rd/.html/}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/rd/dot.rd2rc \
		${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}/rd/dot.rd2rc
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/rd
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/rd/dot.rd2rc \
		${DESTDIR}${PREFIX}/${RUBY_EG}/rd/dot.rd2rc

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
