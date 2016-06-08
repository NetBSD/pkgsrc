# $NetBSD: Makefile,v 1.17 2016/06/08 19:25:09 wiz Exp $

DISTNAME=	Kwiki-PagePrivacy-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki page-level privacy plugin

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/PagePrivacy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
