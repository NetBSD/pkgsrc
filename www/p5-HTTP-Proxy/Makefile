# $NetBSD: Makefile,v 1.9 2011/08/14 16:05:58 obache Exp $
#

DISTNAME=	HTTP-Proxy-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Proxy/
COMMENT=	Perl5 module providing a simple HTTP proxy daemon
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libwww>=2.0:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTTP/Proxy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
