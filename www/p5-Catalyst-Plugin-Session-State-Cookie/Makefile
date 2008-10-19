# $NetBSD: Makefile,v 1.4 2008/10/19 19:19:06 he Exp $

DISTNAME=	Catalyst-Plugin-Session-State-Cookie-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
