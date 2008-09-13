# $NetBSD: Makefile,v 1.3 2008/09/13 13:51:54 he Exp $

DISTNAME=	Catalyst-Plugin-Session-State-Cookie-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-State-Cookie/
COMMENT=	Maintain session IDs using cookies

DEPENDS+=	p5-Catalyst-Runtime>=5.7010:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.19:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Test-MockObject>=1.01:../../devel/p5-Test-MockObject

PERL5_PACKLIST= auto/Catalyst/Plugin/Session/State/Cookie/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
