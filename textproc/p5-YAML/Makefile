# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 15:56:20 epg Exp $

DISTNAME=	YAML-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	YAML implementation for Perl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/YAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
