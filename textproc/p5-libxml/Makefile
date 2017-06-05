# $NetBSD: Makefile,v 1.29 2017/06/05 14:25:00 ryoon Exp $

DISTNAME=	libxml-perl-0.08
PKGNAME=	p5-libxml-0.08
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libxml-perl/
COMMENT=	Perl module collection for working with XML

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		auto/libxml-perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
