# $NetBSD: Makefile,v 1.2 2008/09/11 11:19:36 he Exp $

DISTNAME=	Catalyst-Plugin-Authentication-0.10007
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication/
COMMENT=	Infrastructure plugin for the Catalyst authentication framework

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=   	p5-Catalyst-Plugin-Session>=0.10:../../www/p5-Catalyst-Plugin-Session
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Authentication/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
