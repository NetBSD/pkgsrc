# $NetBSD: Makefile,v 1.22 2013/12/09 14:17:56 obache Exp $
#

DISTNAME=	wApua-0.05.1
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://fsinfo.cs.uni-sb.de/~abe/wApua/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fsinfo.cs.uni-sb.de/~abe/wApua/
COMMENT=	Web browser for WAP WML

DEPENDS+=	p5-URI>=1.03:../../www/p5-URI
DEPENDS+=	p5-libwww>=5.47:../../www/p5-libwww
DEPENDS+=	p5-Tk>=800.000:../../x11/p5-Tk
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net

PERL5_PACKLIST=		auto/wApua/.packlist

INSTALLATION_DIRS=	share/doc/wApua

post-install:
	cd ${WRKSRC}; \
	for i in COPYING README wApua.rc ; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/share/doc/wApua ; \
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
