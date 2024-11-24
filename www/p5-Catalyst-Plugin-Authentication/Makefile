# $NetBSD: Makefile,v 1.37 2024/11/24 08:31:11 wen Exp $

DISTNAME=	Catalyst-Plugin-Authentication-0.10024
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Plugin-Authentication
COMMENT=	Infrastructure plugin for the Catalyst authentication framework
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Plugin-Session>=0.10:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Catalyst-Runtime-[0-9]*:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

TOOL_DEPENDS+=		p5-Catalyst-Plugin-Session-State-Cookie-[0-9]*:../../www/p5-Catalyst-Plugin-Session-State-Cookie
TOOL_DEPENDS+=		p5-Moose>=2:../../devel/p5-Moose
TOOL_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TOOL_DEPENDS+=		p5-Test-WWW-Mechanize-Catalyst>=0.50:../../www/p5-Test-WWW-Mechanize-Catalyst

MAKE_PARAMS+=		--skipdeps
PERL5_PACKLIST=		auto/Catalyst/Plugin/Authentication/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
