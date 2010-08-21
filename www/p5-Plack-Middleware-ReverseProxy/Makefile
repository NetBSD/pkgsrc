# $NetBSD: Makefile,v 1.2 2010/08/21 16:37:03 seb Exp $

DISTNAME=	Plack-Middleware-ReverseProxy-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Middleware-ReverseProxy/
COMMENT=	Plack middleware to support reverse proxy
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Middleware/ReverseProxy/.packlist

DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-parent-[0-9]*:../../devel/p5-parent

# for test target
BUILD_DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
