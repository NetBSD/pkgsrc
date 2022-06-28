# $NetBSD: Makefile,v 1.35 2022/06/28 11:36:47 wiz Exp $

DISTNAME=	libxml-perl-0.08
PKGNAME=	p5-libxml-0.08
PKGREVISION=	18
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/libxml-perl
COMMENT=	Perl module collection for working with XML

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		auto/libxml-perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
