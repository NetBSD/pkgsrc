# $NetBSD: Makefile,v 1.7 2005/02/20 16:19:12 taca Exp $
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
DEPENDS+=	${RUBY_PKGPREFIX}-iconv>=${RUBY_REQD}:../../converters/ruby${RUBY_VER}-iconv
.else
DEPENDS+=	${RUBY_PKGPREFIX}-iconv>=${RUBY_REQD}:../../converters/ruby-iconv
.endif

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
