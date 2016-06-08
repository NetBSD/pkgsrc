# $NetBSD: Makefile,v 1.22 2016/06/08 19:25:09 wiz Exp $

DISTNAME=	Kwiki-Archive-Rcs-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki page archive using RCS

DEPENDS+=	p5-Kwiki>=0.38:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Archive/Rcs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
