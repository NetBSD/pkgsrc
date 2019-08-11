# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:56 wiz Exp $

DISTNAME=	Plack-Middleware-Header-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Middleware-Header
COMMENT=	Plack middleware to modify HTTP response headers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Plack/Middleware/Header/.packlist

DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
#DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
