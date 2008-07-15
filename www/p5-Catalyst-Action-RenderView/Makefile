# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:15:03 abs Exp $

DISTNAME=	Catalyst-Action-RenderView-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Action-RenderView/
COMMENT=	Catalyst render action target

DEPENDS+=	p5-Catalyst-Runtime>=5.70:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Data-Visitor>=0.08:../../devel/p5-Data-Visitor

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Action/RenderView/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
