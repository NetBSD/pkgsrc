# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:45 veego Exp $

DISTNAME=	libxml-perl-0.07
PKGNAME=	p5-libxml-0.07
SVR4_PKGNAME=	p5lxm
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.bitsko.slc.ut.us/
COMMENT=	perl module collection for working with XML

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libxml-perl/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
