# $NetBSD: Makefile,v 1.26 2023/07/06 09:42:50 wiz Exp $

DISTNAME=	Plack-App-Proxy-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-App-Proxy
COMMENT=	Plack middleware proxy application
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Plack/App/Proxy/.packlist

#TOOL_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
TOOL_DEPENDS+=		p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TOOL_DEPENDS+=		p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=		p5-AnyEvent-HTTP>=1.44:../../www/p5-AnyEvent-HTTP
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-Plack>=0.9913:../../www/p5-Plack

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
