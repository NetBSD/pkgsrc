# $NetBSD: Makefile,v 1.6 2005/01/30 04:51:10 taca Exp $
#

DISTNAME=	rexml_${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-rexml-${VERSION}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.germane-software.com/archives/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.germane-software.com/software/rexml/
COMMENT=	Pure Ruby XML parser based on Java Electric XML

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "16"
RUBY_ICONV_DIR=	../../converters/ruby${RUBY_VER}-iconv
.else
RUBY_ICONV_DIR=	../../converters/ruby-iconv
.endif

DEPENDS+= {${RUBY_PKGPREFIX}-iconv-[0-9]*,${RUBY_PKGPREFIX}-uconv-[0-9]*}:${RUBY_ICONV_DIR}

VERSION=		3.1.2
USE_RUBY_INSTALL=	yes
RUBY_SIMPLE_INSTALL=	bin/install.rb
NO_BUILD=		yes
NO_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rexml/api
	${CP} -r ${WRKSRC}/docs/* ${RUBY_DOCDIR}/rexml
	${CP} -r ${WRKSRC}/doc/* ${RUBY_DOCDIR}/rexml/api
	${CHMOD} -R -w ${RUBY_DOCDIR}/rexml

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
