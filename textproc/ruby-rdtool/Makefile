# $NetBSD: Makefile,v 1.26 2008/03/13 19:40:51 jlam Exp $

DISTNAME=	rdtool-0.6.20
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://trac.moonwolf.com/rdtool/wiki/
COMMENT=	RD (Ruby Document) converter to HTML/man/etc

PKG_DESTDIR_SUPPORT=	user-destdir

# Since rd2 commands depends its name and it can't rename, we cannot
# install multiple ruby??-rd2 package (unless supported by pkgview.
CONFLICTS+=	ruby[1-9][0-9]-rdtool-*

USE_RUBY_SETUP=	yes
REPLACE_RUBY=	bin/rd2 bin/rdswap

CONF_FILES+=	${RUBY_SITELIBDIR}/rd/dot.rd2rc ${PKG_SYSCONFDIR}/dot.rd2rc

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
		${DESTDIR}${RUBY_SITELIBDIR}/rd/dot.rd2rc
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR}/rd
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RUBY_DOCDIR}/rd
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/rd
	${INSTALL_DATA} ${WRKSRC}/lib/rd/dot.rd2rc \
		${DESTDIR}${RUBY_EXAMPLESDIR}/rd/dot.rd2rc

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
