# $NetBSD: Makefile,v 1.11 2019/06/30 20:17:30 nia Exp $
#

DISTNAME=	HTML-Mason-PSGIHandler-0.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Mason-PSGIHandler
COMMENT=	PSGI handler for HTML::Mason
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
#BUILD_DEPENDS+=	{perl>=5.6.2,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple

DEPENDS+=	p5-CGI-PSGI-[0-9]*:../../www/p5-CGI-PSGI
DEPENDS+=	p5-HTML-Mason-[0-9]*:../../www/p5-HTML-Mason

PERL5_PACKLIST=	auto/HTML/Mason/PSGIHandler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
