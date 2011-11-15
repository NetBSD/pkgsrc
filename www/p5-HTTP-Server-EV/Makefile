# $NetBSD: Makefile,v 1.1.1.1 2011/11/15 06:42:33 hiramatsu Exp $
#

DISTNAME=	HTTP-Server-EV-0.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-EV/
COMMENT=	Asynchronous HTTP server using EV event loop
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/HTTP/Server/EV/.packlist

.include "../../devel/p5-EV/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
