# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:49 wiz Exp $

DISTNAME=	Kwiki-Archive-Cvs-0.104
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
#HOMEPAGE=	http://search.cpan.org/dist/Kwiki-Archive-Cvs/
COMMENT=	Kwiki page archive using CVS

DEPENDS+=	p5-Kwiki>=0.39:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Archive/Cvs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
