# $NetBSD: Makefile,v 1.4 2011/08/14 16:06:07 obache Exp $

DISTNAME=	Starlet-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Starlet/
COMMENT=	Perl 5 Plack based standalone HTTP/1.0 server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Starlet/.packlist

BUILD_DEPENDS+=	p5-Test-TCP>=0.15:../../net/p5-Test-TCP
DEPENDS+=	p5-Parallel-Prefork>=0.07:../../devel/p5-Parallel-Prefork
DEPENDS+=	p5-Plack>=0.992:../../www/p5-Plack
DEPENDS+=	p5-Server-Starter>=0.06:../../sysutils/p5-Server-Starter

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
