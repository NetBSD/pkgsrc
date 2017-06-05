# $NetBSD: Makefile,v 1.12 2017/06/05 14:25:21 ryoon Exp $

DISTNAME=	HTTP-Daemon-6.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Daemon/
COMMENT=	Simple http server class
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

DEPENDS+=	p5-HTTP-Date>=6:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Message>=6.02:../../www/p5-HTTP-Message
DEPENDS+=	p5-LWP-MediaTypes>=6.01:../../www/p5-LWP-MediaTypes

PERL5_PACKLIST=		auto/HTTP/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
