# $NetBSD: Makefile,v 1.1.1.1 2002/06/28 07:40:29 jlam Exp $
#
# This package tracks a snapshot of modperl-2.0 that is updated every 6
# hours.  To update to the latest snapshot, simply change DISTNAME to
# point to the correct distfile at ${MASTER_SITES}.  The PKGNAME is taken
# from ${WRKSRC}/STATUS.
#
# NOTE: This package is *BETA*.  If it doesn't work, then check the
#	modperl-2.0 mailing lists for help.

DISTNAME=		modperl-2.0_20020628042432
PKGNAME=		ap2-perl-1.99.5
WRKSRC=			${WRKDIR}/modperl-2.0
CATEGORIES=		www perl5
MASTER_SITES=		http://cvs.apache.org/snapshots/modperl-2.0/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

DEPENDS+=		apache>=2.0.39:../../www/apache2

# This section should be removed when modperl-2.0 is released.
RESTRICTED=		"Changes frequently; fetch from master site."
NO_SRC_ON_FTP=		${RESTRICTED}
NO_CHECKSUM=		# defined

USE_BUILDLINK_ONLY=	# defined
USE_PERL5=		# defined
PERL5_REQD=		5.6.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

MAKE_PARAMS+=		MP_APXS=${LOCALBASE}/sbin/apxs

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

post-configure:
	for file in ${WRKSRC}/xs/modperl_xs_typedefs.h; do		\
		${MV} -f $${file} $${file}.orig;			\
		${GREP}	-v "apr_thread_mutex_t"				\
			$${file}.orig > $${file};			\
	done

.include "../../mk/bsd.pkg.mk"
